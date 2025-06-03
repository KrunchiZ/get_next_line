/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:08:26 by kchiang           #+#    #+#             */
/*   Updated: 2025/06/03 20:35:14 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

/* Default BUFFER_SIZE if not defined in terminal */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/* Soft limits for max file descriptor limit */
# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

char	*get_next_line(int fd);
int		has_newline(char *buffer);
char	*extract_buffer(char *buffer);
char	*string_transfer(char *src);

#endif
