/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coordinates.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/10 11:49:29 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/14 11:06:40 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	is_line_contain_letter(char **tetriminos, int line)
{
	int j;

	j = 0;
	while (j < 4)
	{
		if (ft_is_upper(tetriminos[line][j]) == 1)
			return (1);
		j++;
	}
	return (0);
}

static int	is_column_contain_letter(char **tetriminos, int column)
{
	int i;

	i = 0;
	while (i < 4)
	{
		if (ft_is_upper(tetriminos[i][column]) == 1)
			return (1);
		i++;
	}
	return (0);
}

static void	get_x_coord(t_tetriminos *tetris)
{
	int column;

	column = 0;
	while (column < 4)
	{
		if (is_column_contain_letter(tetris->tetriminos, column) == 1)
		{
			tetris->start_x = column;
			while (is_column_contain_letter(tetris->tetriminos, column) == 1 &&
			column < 4)
				column++;
			tetris->end_x = column - 1;
		}
		column++;
	}
}

static void	get_y_coord(t_tetriminos *tetris)
{
	int line;

	line = 0;
	while (line < 4)
	{
		if (is_line_contain_letter(tetris->tetriminos, line) == 1)
		{
			tetris->start_y = line;
			while (line < 4 && (is_line_contain_letter(tetris->tetriminos,
			line) == 1))
				line++;
			tetris->end_y = line - 1;
		}
		line++;
	}
}

void		coordinates(t_tetriminos *tetris)
{
	initialize_coord(tetris);
	get_x_coord(tetris);
	get_y_coord(tetris);
}
