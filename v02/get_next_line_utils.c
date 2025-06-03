/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:12:43 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/03 20:32:59 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/* FUNCTIONS FOR BUFFER CHECKING WHEN GET_NEXT_LINE GETS RECALLED             */
/* ************************************************************************** */

/* Check to see if previous buffer has a complete line
 */
int	has_newline(char *buffer)
{
	while (*buffer)
	{
		if (*buffer == '\n')
			return (1);
		buffer++;
	}
	return (0);
}

/* Extract a newline terminated line from buffer and return it.
 * After extracting, shift the remaining string to the front of buffer.
 */
char	*extract_buffer(char *buffer)
{
	char	*host;
	int		len;
	int		i;
	int		start;

	len = 0;
	while (buffer[len] != '\n')
		len++;
	host = malloc(sizeof(char) * (len + 2));
	if (!host)
		return (NULL);
	i = 0;
	while (i < len)
	{
		host[i] = buffer[i];
		i++;
	}
	host[i++] = '\n';
	host[i] = '\0';
	start = 0;
	while (buffer[i])
		buffer[start++] = buffer[i++];
	buffer[start] = '\0';
	return (host);
}

/* Parse the non newline ended, null terminated src string into dest
 */
char	*string_transfer(char *src)
{
	int		i;
	char	*dest;

	i = 0;
	while (src[i])
		i++;
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
