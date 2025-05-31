/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 12:30:08 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*read_line(char *buffer, int *len)
{
}

/* Buffer has to be null terminated to differentiate between true complete
 * line and unfinished line.
 * Buffer will be freed if whole buffer has been parsed back to host.      */
char	*get_next_line(int fd)
{
	int			rbytes;
	char		*host;
	static char	*buffer[MAX_FDS];

	if (fd < 0)
		return (NULL);
	if (buffer[fd])
	{
		if (buffer_has_newline(tmp[fd]))
			return (extract_buffer(buffer[fd]));
		host = buffer_to_host(buffer[fd]);
	}
	buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer[fd])
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	rbytes = read(fd, buffer[fd], BUFFER_SIZE);
}
