/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amane <amane@studente.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 10:17:27 by amane             #+#    #+#             */
/*   Updated: 2022/03/22 12:22:16 by amane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*apt_str;
	unsigned int	size;

	size = len;
	apt_str = (char *) b;
	while (size--)
		*apt_str++ = c;
	return (b);
}


void	*ft_calloc(size_t count, size_t size)
{
	void	*alocacao;

	alocacao = (void *) malloc(size * count);
	if (!alocacao)
		return (0);
	ft_memset(alocacao, 0, (size * count));
	return (alocacao);
}

size_t	lentonewline(const char *str)
{
	size_t		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		++i;
	}
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;

	if (!s1 || !s2)
		return (0);
	new = (char *)malloc((ft_strlen(s1) + lentonewline(s2) + 1) * sizeof(char));
	if (!new)
		return (0);
	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	while (s2[j] && s2[j] != '\n')
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	new[i] = 0;
	return (new);
}

char	*ft_strdup(const char *s1)
{
	char	*ptr;
	int		n;

	n = 0;
	while (s1[n])
		n++;
	ptr = malloc(sizeof(char) * (n + 1));
	if (!ptr)
		return (0);
	n = 0;
	while (s1[n])
	{
		ptr[n] = s1[n];
		n++;
	}
	ptr[n] = '\0';
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	char	*chr;

	chr = (char *) s;
	while ((char) c != *chr)
	{
		if (*chr == 0)
			return (0);
		++ chr;
	}
	return (chr);
}
