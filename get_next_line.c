/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amane <amane@studente.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 14:22:41 by amane             #+#    #+#             */
/*   Updated: 2022/03/22 12:52:44 by amane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	find_char(char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i ++;
	}
	return (0);
}

size_t	ft_strlen(const char *s)
{
	size_t		i;

	i = 0;
	while (s[i] != 0)
	{
		i ++;
	}
	return (i);
}

char	*get_next_line(int fd)
{
	size_t		r;
	char		*str;
	char		*apt;
	char		*tmp;

	r = 1;
	apt = (char *) ft_calloc(BUFFER_SIZE, sizeof(char));
	str = (char *) malloc(sizeof(char));
	while (r > 0 && !find_char(apt, '\n'))
	{
		r = read(fd, apt, BUFFER_SIZE);
		tmp = ft_strdup(str);
		free(str);
		str = ft_strjoin(tmp, apt);
		free(tmp);
	}
	free(apt);
	return (str);
}
