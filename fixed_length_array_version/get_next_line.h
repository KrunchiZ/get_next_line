/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kchiang <kchiang@student.42kl.edu.my>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 12:08:26 by kchiang           #+#    #+#             */
/*   Updated: 2025/10/22 20:01:07 by kchiang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

/* Default BUFFER_SIZE if not defined in terminal */
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

/* Soft limits for max file descriptor limit */
# ifndef MAX_FDS
#  define MAX_FDS 1024
# endif

char	*get_next_line(int fd);
int		has_newline(char *str);
void	*extract_buffer(char *str);
char	*string_transfer(char *src);
char	*join_host_buffer(char *host, char *buffer, int rbytes);
char	*read_fd(char *host, char *buffer, int fd);

#endif
