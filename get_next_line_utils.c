/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:12:43 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 17:46:34 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Check to see if previous buffer has a complete line */
int	buffer_has_line(char *str)
{
	while (*str)
	{
		if (*str++ == '\n')
			return (1);
	}
	return (0);
}

/* Extract a line from tmp and return it                          */
/* After extracting, shift the remaining char to the front of str */
void	*extract_buffer(char *str)
{
	char	*host;
	int		len;
	int		i;
	int		start;

	len = 0;
	while (str[len] != '\n')
		len++;
	host = malloc(sizeof(char) * (len + 2));
	if (!host)
		return (NULL);
	i = 0;
	while (i < len)
	{
		host[i] = str[i];
		i++;
	}
	host[i++] = '\n';
	host[i] = '\0';
	start = 0;
	while (str[i])
		str[start++] = str[i++];
	str[start] = '\0';
	return (host);
}

/* Parse the non newline ended, null terminated buffer str into host, */
/* then free buffer                                                   */
char	*buffer_to_host(char *buffer)
{
	char	*host;
	int		len;
	int		i;

	len = 0;
	while (buffer[len])
		len++;
	host = malloc(sizeof(char) * (len + 1));
	if (!host)
		return (NULL);
	i = 0;
	while (buffer[i])
	{
		host[i] = buffer[i];
		i++;
	}
	host[i] = '\0';
	free(buffer);
	return (host);
}

/* Join host and buffer together into a new malloc string and return it. */
/* Host will be freed after parsing to new_host                          */
char	*host_buffer_join(char *host, char *buffer, int rbytes)
{
	int		i;
	int		j;
	int		start;
	char	*new_host;

	i = 0;
	while (host[i])
		i++;
	new_host = malloc(sizeof(char) * (i + rbytes + 1));
	j = i;
	while (j-- > 0)
		new_host[j] = host[j];
	free(host);
	while (j < rbytes && buffer[j] != '\n')
		new_host[i++] = buffer[j++];
	if (j < rbytes)
		new_host[i++] = '\n';
	new_host[i] = '\0';
	start = 0;
	while (j < rbytes)
		buffer[start++] = buffer[j++];
	buffer[start] = '\0';
	return (new_host);
}

char	*read_line(char *buffer, char *host, int fd)
{
	int		rbytes;
	char	*new_host;

	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (!rbytes)
		return (NULL);
	new_host = host_buffer_join(host, buffer, rbytes);
	if (!new_host)
		return (NULL);
	return (new_host);
}
