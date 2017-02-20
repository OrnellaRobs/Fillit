/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_hash_touch.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/16 22:15:03 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/18 11:55:20 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_other_cells(char **tetris, int line, int column,
	int count_link)
{
	int keep_count_link;

	keep_count_link = count_link;
	if (column >= 1 && ft_is_upper(tetris[line][column - 1]) == 1)
		count_link++;
	if (column <= 2 && ft_is_upper(tetris[line][column + 1]) == 1)
		count_link++;
	if (line >= 1 && ft_is_upper(tetris[line - 1][column]) == 1)
		count_link++;
	if (line <= 2 && ft_is_upper(tetris[line + 1][column]) == 1)
		count_link++;
	if (count_link == keep_count_link)
		return (-1);
	return (count_link);
}

static int	checking(char **tetris)
{
	int line;
	int column;
	int count_link;

	line = 0;
	count_link = 0;
	while (tetris[line])
	{
		column = 0;
		while (tetris[line][column])
		{
			if (ft_is_upper(tetris[line][column]) == 1)
			{
				if (check_other_cells(tetris, line, column, count_link) == -1)
					return (-1);
				count_link = check_other_cells(tetris, line, column,
				count_link);
			}
			if (count_link == 6 || count_link == 8)
				return (1);
			column++;
		}
		line++;
	}
	return (-1);
}

int			check_hash_touch(t_tetriminos *tmp)
{
	while (tmp)
	{
		if (checking(tmp->tetriminos) == -1)
			return (-1);
		tmp = tmp->tetris_next;
	}
	return (1);
}
