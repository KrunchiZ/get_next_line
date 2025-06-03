/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/04 00:06:01 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Join host and buffer together into a new malloc string and return it.
 * Host will be freed after parsing to new_host.
 */
static char	*join_host_buffer(char *host, char *buffer, int rbytes)
{
	int		i;
	int		j;
	char	*new_host;

	i = 0;
	while (host[i])
		i++;
	new_host = malloc(sizeof(char) * (i + rbytes + 1));
	if (!new_host)
		return (NULL);
	j = i;
	while (j-- > 0)
		new_host[j] = host[j];
	j = 0;
	while (j < rbytes && buffer[j] != '\n')
		new_host[i++] = buffer[j++];
	if (j < rbytes)
		new_host[i++] = buffer[j++];
	new_host[i] = '\0';
	i = 0;
	while (j < rbytes)
		buffer[i++] = buffer[j++];
	buffer[i] = '\0';
	return (free(host), new_host);
}

/* Read fd and combine host(if there's any from previous g_n_line call) with
 * buffer until end of first line into new_host.
 * If host is NULL, malloc an empty string into host.
 *
 * Leftover characters gets shifted to the front and stays in buffer to be
 * processed by extract_buffer or string_transfer in the next g_n_line call.
 *
 * When end of file has been reached (0 rbytes), free host(empty string or NULL)
 * then return NULL.
 *
 * If incomplete line is found after read, line will be transferred from
 * new_host back to a freed buffer.
 */
static char	*read_fd(char *host, char *buffer, int fd)
{
	int		rbytes;
	char	*new_host;

	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes <= 0)
		return (host);
	if (!host)
	{
		host = malloc(sizeof(char) * 1);
		if (!host)
			return (NULL);
		host[0] = '\0';
	}
	new_host = join_host_buffer(host, buffer, rbytes);
	if (!new_host)
		return (NULL);
	if (!has_newline(new_host))
	{
		host = string_transfer(new_host);
		free(new_host);
		new_host = read_fd(host, buffer, fd);
	}
	return (new_host);
}

/* Buffer has to be null terminated to differentiate between true complete
 * line and unfinished line.
 * 
 * Non \n terminated buffer will be freed in 'buffer_to_host' after getting
 * parsed to host.
 */
char	*get_next_line(int fd)
{
	char		*host;
	static char	buffer[MAX_FDS][BUFFER_SIZE + 1];

	if (fd < 0)
		return (NULL);
	host = NULL;
	if (has_newline(buffer[fd]))
		return (extract_buffer(buffer[fd]));
	host = string_transfer(buffer[fd]);
	buffer[fd][0] = '\0';
	host = read_fd(host, buffer[fd], fd);
	if (host)
		return (host);
	return (NULL);
}
