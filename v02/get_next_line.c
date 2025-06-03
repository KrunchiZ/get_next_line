/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/03 20:37:25 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Join host and buffer together into a new malloc string and return it.
 * Host will be freed after parsing to new_host.
 */
static char	*join_temp_buffer(char *temp, char *buffer, int rbytes)
{
	int		i;
	int		j;
	char	*host;

	i = 0;
	while (temp[i])
		i++;
	host = malloc(sizeof(char) * (i + rbytes + 1));
	if (!host)
		return (NULL);
	j = i;
	while (j-- > 0)
		host[j] = temp[j];
	j = 0;
	while (j < rbytes && buffer[j] != '\n')
		host[i++] = buffer[j++];
	if (j < rbytes)
		host[i++] = buffer[j++];
	host[i] = '\0';
	i = 0;
	while (j < rbytes)
		buffer[i++] = buffer[j++];
	buffer[i] = '\0';
	return (host);
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
static char	*read_fd(char *temp, char *buffer, int fd)
{
	int		rbytes;
	char	*host;

	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes <= 0)
		return (NULL);
	host = join_temp_buffer(temp, buffer, rbytes);
	if (!host)
		return (NULL);
	if (!has_newline(host))
	{
		string_transfer(temp, host);
		free(host);
		host = read_fd(temp, buffer, fd);
	}
	return (host);
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
	//CHECK FOR NULL HOST FROM STRING TRANSFER
	buffer[fd][BUFFER_SIZE] = '\0';
	host = read_fd(host, buffer[fd], fd);
	if (!host)
		return (NULL);
	return (host);
}
