/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amane <amane@studente.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:40:45 by amane             #+#    #+#             */
/*   Updated: 2022/03/22 12:49:08 by amane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
# define GET_NEXT_LINE
# define BUFFER_SIZE 2

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>

size_t	ft_strlen(const char *s);
char	*get_next_line(int fd);
void	*ft_calloc(size_t count, size_t size);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *s1);
char	*findnewline(const char *s, int c);
char	*ft_strchr(const char *s, int c);

#endif