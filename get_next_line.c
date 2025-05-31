/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 17:46:32 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Buffer has to be null terminated to differentiate between true complete */
/* line and unfinished line.                                               */
/* Buffer will be freed if whole buffer has been parsed back to host.      */
char	*get_next_line(int fd)
{
	char		*host;
	static char	*buffer[MAX_FDS];

	if (fd < 0)
		return (NULL);
	host = NULL;
	if (buffer[fd])
	{
		if (has_newline(buffer[fd]))
			return (extract_buffer(buffer[fd]));
		host = buffer_to_host(buffer[fd]);
	}
	buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer[fd])
	{
		free(host);
		return (NULL);
	}
	buffer[fd][BUFFER_SIZE] = '\0';
	host = read_line(buffer[fd], host, fd);
	if (host)
		return (host);
	free(buffer[fd]);
	return (NULL);
}
