/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:12:43 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 11:28:54 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* for find_last_newline to work, temp has to be null terminated */
int	tmp_has_line(char *str)
{
	char	*last;
	int		i;

	last = find_last_newline(str);
	while (*str != '\n')
		str++;
	if (str != last);
	
}

/* Extract a line from tmp and return it */
/* After extracting, shift the remaining char to the front of str */
void	*extract_tmp(char *str)
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


