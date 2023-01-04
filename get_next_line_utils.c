/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amane <amane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:38:03 by amane             #+#    #+#             */
/*   Updated: 2023/01/04 12:38:08 by amane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	cont;

	cont = 0;
	if (str == NULL)
		return (0);
	while (str[cont] != '\0')
	{
		if (str[cont] == '\n')
			return (cont + 1);
		cont ++;
	}
	return (cont);
}

char	*copy_new_str(char *buff, char *line)
{
	char	*aux;
	int		i;
	int		j;

	i = 0;
	aux = line;
	line = malloc(sizeof(char) * (ft_strlen(buff) + ft_strlen(line) + 1));
	if (!line)
		return (0);
	j = 0;
	while (aux && aux[i])
	{
		line [i] = aux[i];
		i++;
	}
	while (buff[j])
	{
		line[i++] = buff[j];
		if (buff[j++] == '\n')
			break ;
	}
	line[i] = '\0';
	if (aux)
		free(aux);
	return (line);
}

void	save_last_nline(char *buff)
{
	int	i;
	int	j;

	j = -1;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n' && j == -1)
			j = 0;
		else if (j >= 0)
		{
			buff[j] = buff[i];
			j++;
		}
		buff[i++] = 0;
	}
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			return ((char *)&s[i]);
		i ++;
	}
	if (c == 0)
		return ((char *)&s[i]);
	return (0);
}
