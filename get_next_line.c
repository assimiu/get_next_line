/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amane <amane@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:38:13 by amane             #+#    #+#             */
/*   Updated: 2023/01/04 12:38:18 by amane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	buff[BUFFER_SIZE];
	char		*line;
	int			check;
	int			i;

	if (fd < 0 || fd > 1024 || BUFFER_SIZE < 1 || read(fd, 0, 0) == -1)
		return (NULL);
	i = 1;
	line = NULL;
	while (i)
	{
		check = 1;
		if (!buff[0])
			check = read(fd, buff, BUFFER_SIZE);
		if (check > 0)
			line = copy_new_str(buff, line);
		save_last_nline(buff);
		if (!check || ft_strchr(line, '\n'))
			break ;
	}
	return (line);
}
