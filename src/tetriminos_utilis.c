/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tetriminos_utilis.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 14:09:56 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/18 14:36:12 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static char				**split_array_tetriminos(char **array_tmp,
	char **array_tetriminos, int tmp)
{
	int i;

	i = 0;
	while (i < 4)
	{
		array_tmp[i] = ft_strdup(array_tetriminos[tmp]);
		i++;
		tmp++;
	}
	array_tmp[i] = NULL;
	return (array_tmp);
}

static t_double_list	*push_tetriminos_to(t_double_list *li,
	char **array_tetriminos, int tmp)
{
	char **array_tmp;

	array_tmp = malloc(sizeof(char *) * 4 + 1);
	array_tmp = split_array_tetriminos(array_tmp, array_tetriminos, tmp);
	li = push_back_dlist(li, array_tmp);
	return (li);
}

t_double_list			*get_list_tetriminos(t_double_list *li, char *buff)
{
	char	**array_tetriminos;
	int		tmp;

	tmp = 0;
	array_tetriminos = ft_strsplit_fillit((char const *)buff, '\n');
	while (array_tetriminos[tmp])
	{
		li = push_tetriminos_to(li, array_tetriminos, tmp);
		tmp += 4;
	}
	li = change_hash_into_alpha(li);
	return (li);
}
