/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:12:43 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 12:28:52 by kchiang          ###   ########.fr       */
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

/* Extract a line from tmp and return it
 * After extracting, shift the remaining char to the front of str */
void	*extract_buffer(char *str)
{
	char	*host;
	int		len;
	int		i;
	int		new;

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
	new = 0;
	while (str[i])
		str[new++] = str[i++];
	str[new] = '\0';
	return (host);
}

/* Parse the non newline ended, null terminated buffer str into host,
 * then free buffer                                                   */
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
