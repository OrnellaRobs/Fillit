/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/18 14:03:48 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/18 14:43:08 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	free_double_array(char **array)
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

static void	free_linked_list(t_tetriminos *tmp)
{
	t_tetriminos *save_next;

	while (tmp)
	{
		save_next = tmp->tetris_next;
		free_double_array(tmp->tetriminos);
		free(tmp);
		tmp = save_next;
	}
}

void		free_all(char **final_array, t_tetriminos *tmp)
{
	free_double_array(final_array);
	free_linked_list(tmp);
}
