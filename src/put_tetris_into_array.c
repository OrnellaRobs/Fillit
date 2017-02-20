/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tetris_into_array.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/31 16:55:02 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/14 11:27:12 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char	what_letter_is_it(char **tetriminos)
{
	int line;
	int column;

	line = 0;
	column = 0;
	while (tetriminos[line])
	{
		while (tetriminos[line][column])
		{
			if (ft_is_upper(tetriminos[line][column]) == 1)
				return (tetriminos[line][column]);
			column++;
		}
		column = 0;
		line++;
	}
	return ('0');
}

static char	**remove_letter(char **array, char **tetriminos)
{
	int		line;
	int		column;
	char	letter;

	line = 0;
	column = 0;
	letter = what_letter_is_it(tetriminos);
	while (array[line])
	{
		while (array[line][column])
		{
			if (array[line][column] == letter)
				array[line][column] = '.';
			column++;
		}
		column = 0;
		line++;
	}
	return (array);
}

static char	**put_one_tetris(char **array, t_tetriminos *tetris, int line,
	int column)
{
	int k_start_x;
	int k_start_y;
	int column_x;

	k_start_x = tetris->start_x;
	k_start_y = tetris->start_y;
	column_x = column;
	while (k_start_y <= tetris->end_y)
	{
		while (k_start_x <= tetris->end_x)
		{
			if (ft_is_upper(tetris->tetriminos[k_start_y][k_start_x]) == 1)
				array[line][column] = tetris->tetriminos[k_start_y][k_start_x];
			k_start_x++;
			column++;
		}
		k_start_y++;
		k_start_x = tetris->start_x;
		line++;
		column = column_x;
	}
	return (array);
}

char		**put_tetris_into_array(t_tetriminos *tetris, char **array,
	int line, int column)
{
	if (tetris == NULL)
		return (array);
	if (array[line] == NULL)
		return (NULL);
	else if (check_collision(array, tetris, line, column) == -1)
	{
		if (array[line][column] == '\0')
			return (put_tetris_into_array(tetris, array, line + 1, 0));
		return (put_tetris_into_array(tetris, array, line, column + 1));
	}
	else if (check_collision(array, tetris, line, column) == 1)
	{
		array = put_one_tetris(array, tetris, line, column);
		tetris = tetris->tetris_next;
		if (put_tetris_into_array(tetris, array, 0, 0))
			return (array);
		tetris = tetris->tetris_prev;
		array = remove_letter(array, tetris->tetriminos);
		return (put_tetris_into_array(tetris, array, line, column + 1));
		return (NULL);
	}
	return (array);
}
