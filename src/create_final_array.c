/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_final_array.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/03 22:02:56 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/10 20:24:38 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_and_initialize_final_array_with_dots(int size)
{
	char	**final_array;
	int		i;
	int		j;

	if (!(final_array = malloc(sizeof(char *) * (size + 1))))
		return (NULL);
	i = 0;
	while (i < size)
	{
		if (!(final_array[i] = malloc(sizeof(char) * (size + 1))))
			return (NULL);
		j = 0;
		while (j < size)
		{
			final_array[i][j] = '.';
			j++;
		}
		final_array[i][j] = '\0';
		i++;
	}
	final_array[i] = NULL;
	return (final_array);
}
