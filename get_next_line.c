/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:07:50 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/30 20:01:29 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*checkline(char *buffer)
{
}

void	*read_line(char *buffer, int *len)
{
	int		i;
	char	*host;

	*len = 0;
	while (*len < BUFFER_SIZE && buffer[*len] != '\n')
		(*len)++;
	if (*len < BUFFER_SIZE)
		host = malloc(sizeof(char) * ((*len)++ + 2));
	else
		host = malloc(sizeof(char) * ((*len) + 1));
	if (!host)
		return (NULL);
	i = 0;
	while (i < *len)
	{
		host[i] = buffer[i];
		i++;
	}
	if (i < BUFFER_SIZE)
	{
		host[i++] = '\n';
		host[i] = '\0';
	}
	else
		host[i] = '\0';
	return (host);
}

char	*get_next_line(int fd)
{
	int		rbytes;
	int		len;
	char	*host;
	char	buffer[BUFFER_SIZE];
	char	*temp[BUFFER_SIZE];

	if (fd < 0)
		return (NULL);
	buffer = m;
	if (!buffer)
		return (NULL);
	buffer[BUFFER_SIZE] = '\0';
	rbytes = read(fd, buffer, BUFFER_SIZE);
	if (rbytes < 1)
		return (NULL);
	host = read_line(buffer, &len);
	if (!host)
		return (NULL);
	if (len < rbytes)
	{
		first_node = 
	}
}
