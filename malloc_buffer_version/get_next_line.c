/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/04 13:21:06 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* Buffer is null terminated to differentiate between true complete
 * line and unfinished line.
 * 
 * Non \n terminated buffer will be freed in 'string_transfer' after getting
 * parsed to host.
 */
char	*get_next_line(int fd)
{
	char		*host;
	static char	*buffer[MAX_FDS];

	if (fd < 0 || fd > MAX_FDS || BUFFER_SIZE <= 0)
		return (NULL);
	host = NULL;
	if (buffer[fd])
	{
		if (has_newline(buffer[fd]))
			return (extract_buffer(buffer[fd]));
		host = string_transfer(buffer[fd]);
	}
	buffer[fd] = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer[fd])
		return (free(host), NULL);
	buffer[fd][0] = '\0';
	host = read_fd(host, buffer[fd], fd);
	if (host)
		return (host);
	free(buffer[fd]);
	buffer[fd] = NULL;
	return (NULL);
}
