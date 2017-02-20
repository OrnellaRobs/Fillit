/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialize_coordinates.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/01 23:04:00 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/07 16:06:46 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initialize_coord(t_tetriminos *tetris)
{
	tetris->start_x = -1;
	tetris->start_y = -1;
	tetris->end_x = -1;
	tetris->end_y = -1;
}
