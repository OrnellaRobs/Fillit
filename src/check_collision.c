/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 21:49:31 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/18 13:23:51 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_collision(char **array, t_tetriminos *tetris, int line, int column)
{
	int	k_start_x;
	int k_start_y;
	int column_x;

	k_start_x = tetris->start_x;
	k_start_y = tetris->start_y;
	column_x = column;
	while (array[line] && k_start_y <= tetris->end_y)
	{
		while (array[line][column] && k_start_x <= tetris->end_x)
		{
			if (ft_is_upper(tetris->tetriminos[k_start_y][k_start_x]) == 1
			&& array[line][column] != '.')
				return (-1);
			k_start_x++;
			column++;
		}
		if (k_start_x - 1 < tetris->end_x)
			return (-1);
		k_start_x = tetris->start_x;
		k_start_y++;
		line++;
		column = column_x;
	}
	return (k_start_y - 1 < tetris->end_y) ? -1 : 1;
}
