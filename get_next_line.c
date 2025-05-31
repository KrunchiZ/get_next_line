/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 11:29:37 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*read_line(char *buffer, int *len)
{
}

char	*get_next_line(int fd)
{
	int			rbytes;
	char		*host;
	char		buffer[BUFFER_SIZE];
	static char	*tmp[MAX_FDS];

	if (fd < 0)
		return (NULL);
	if (tmp_has_newline(tmp[fd]))
		return (extract_tmp(tmp[fd]));
}
