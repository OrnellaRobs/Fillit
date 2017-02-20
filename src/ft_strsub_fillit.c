/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub_fillit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/10 18:54:49 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/10 18:55:05 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_strsub_fillit(char const *s, unsigned int start, size_t len)
{
	char	*copy_s;
	size_t	i;

	if (!s)
		return (NULL);
	if (!(copy_s = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	i = 0;
	while (i < len)
	{
		copy_s[i] = s[start];
		i++;
		start++;
	}
	copy_s[i] = '\0';
	return (copy_s);
}
