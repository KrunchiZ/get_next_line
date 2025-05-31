/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:08:26 by kchiang           #+#    #+#             */
/*   Updated: 2025/05/31 17:38:42 by kchiang          ###   ########.fr       */
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

int		buffer_has_line(char *str);
void	*extract_buffer(char *str);
char	*buffer_to_host(char *buffer);
char	*host_buffer_join(char *host, char *buffer, int rbytes);
char	*read_line(char *buffer, char *host, int fd);

#endif
