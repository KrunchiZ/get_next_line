/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:12:43 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/03 19:41:44 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/* FUNCTIONS FOR BUFFER CHECKING WHEN GET_NEXT_LINE GETS RECALLED             */
/* ************************************************************************** */

/* Check to see if previous buffer has a complete line
 */
int	has_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str++ == '\n')
			return (1);
	}
	return (0);
}

/* Extract a line from tmp and return it.
 * After extracting, shift the remaining char to the front of str.
 */
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

/* Parse the non newline ended, null terminated src string into dest,
 * then free src.
 * Basically a modified ft_strdup.
 */
char	*string_transfer(char *src)
{
	char	*dest;
	int		i;

	i = 0;
	while (src[i])
		i++;
	if (!i)
		return (free(src), NULL);
	dest = malloc(sizeof(char) * (i + 1));
	if (!dest)
		return (free(src), NULL);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (free(src), dest);
}
