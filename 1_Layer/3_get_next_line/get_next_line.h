/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: regea-go <regea-go@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/08 21:05:55 by regea-go          #+#    #+#             */
/*   Updated: 2023/05/24 22:55:46 by regea-go         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

size_t	ft_strlen(const char *str);
char	*copy_line(char *str);
char	*get_next_line(int fd);
char	*update_buffer(char	*buffer);
char	*read_line(char *buffer, int fd);
size_t	ft_linelen(char *str);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin(char *buffer, char *aux);
char	*ft_free(char **str);

#endif
