/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amane <amane@studente.42lisboa.com>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 09:56:07 by amane             #+#    #+#             */
/*   Updated: 2022/03/22 12:51:13 by amane            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		o;

	printf("Compilacao\n");
	o = open("txt.txt", O_RDONLY);
	printf("%s\n", get_next_line(o));
	
}
