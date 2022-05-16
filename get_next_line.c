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

static char		*resto_lido;

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

char	*findnewline(const char *s, int c)
{
	size_t		i;
	char		*apt;

	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		++ i;
	}
	apt = (char *) malloc(sizeof(char) * (i + 1));
	i = 0;
	while (s[i] != c && s[i] != 0)
	{
		apt[i] = s[i];
		i ++;
	}
	apt[i] = 0;
	return (apt);
}

char	*get_next_line(int fd)
{
	size_t		r;
	size_t		i;
	size_t		lenft;
	char		*retorno;
	char		*apt;
	
	apt = (char *) ft_calloc(BUFFER_SIZE, sizeof(char));
	r = read(fd, apt, BUFFER_SIZE);
	retorno = findnewline(apt, '\n');
	i = ft_strlen(retorno);
	lenft = ft_strlen(apt);
	if (resto_lido != 0)
		retorno = ft_strjoin(resto_lido, retorno);
	resto_lido = (char *) malloc(sizeof(char) * (lenft - i + 1));
	lenft = 0;
	while (apt[i] != 0)
	{
		resto_lido[lenft] = apt[i];
		i ++;
		lenft ++;
	}
	resto_lido[lenft] = 0;
	return (retorno);
}
