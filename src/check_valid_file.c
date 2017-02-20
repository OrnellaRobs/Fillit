/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_file.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/14 16:15:02 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/18 11:52:17 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_column_and_valid_char(char *buff, int i, int count_column)
{
	while (buff[i] != '\n' && buff[i] != '\0')
	{
		if (buff[i] != '.' && buff[i] != '#')
			return (-1);
		count_column++;
		i++;
	}
	return (count_column);
}

static int	check_four_line_and_four_column(char *buff, int count_line,
int count_column)
{
	int i;

	i = 0;
	while (buff[i])
	{
		count_column = check_column_and_valid_char(buff, i, count_column);
		if (count_column != 4)
			return (-1);
		i += 4;
		count_column = 0;
		count_line++;
		if (buff[i + 1] == '\n' || buff[i + 1] == '\0')
		{
			if (count_line != 4)
				return (-1);
			count_line = 0;
			i++;
		}
		i++;
	}
	return (1);
}

static int	check_how_many_hash_by_tetriminos(char *buff)
{
	int i;
	int	count_hash;

	i = 0;
	count_hash = 0;
	while (buff[i])
	{
		while (buff[i] != '\n' && buff[i] != '\0')
		{
			if (buff[i] == '#')
				count_hash++;
			i++;
		}
		if (buff[i + 1] == '\n' || buff[i + 1] == '\0')
		{
			if (count_hash != 4)
				return (-1);
			count_hash = 0;
			i++;
		}
		i++;
	}
	return (1);
}

int			check_valid_file(char *buff)
{
	int count_line;
	int count_column;

	count_line = 0;
	count_column = 0;
	if (check_four_line_and_four_column(buff, count_line, count_column) == -1)
		return (-1);
	if (check_how_many_hash_by_tetriminos(buff) == -1)
		return (-1);
	return (1);
}
