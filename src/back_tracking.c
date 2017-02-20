/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   back_tracking.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 21:49:08 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/14 11:03:44 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_array(char **array)
{
	int line;

	line = 0;
	while (array[line])
	{
		free(array[line]);
		line++;
	}
	free(array);
}

static char	**extend_array(int size)
{
	char **new_array;

	new_array = create_and_initialize_final_array_with_dots(size);
	return (new_array);
}

static int	size_array(char **array)
{
	int line;
	int size;

	line = 0;
	size = 0;
	while (array[line] != NULL)
	{
		line++;
		size++;
	}
	return (size);
}

char		**put_all(t_tetriminos *tmp, char **array, int line, int column)
{
	char	**array_tmp;
	int		size;

	size = size_array(array);
	array_tmp = put_tetris_into_array(tmp, array, line, column);
	if (array_tmp == NULL)
	{
		free_array(array);
		array = extend_array(size + 1);
		while (tmp->tetris_prev)
			tmp = tmp->tetris_prev;
		return (put_all(tmp, array, 0, 0));
	}
	return (array);
}
