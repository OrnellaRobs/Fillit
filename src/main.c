/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 00:19:31 by orazafin          #+#    #+#             */
/*   Updated: 2017/04/07 15:51:58 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int				open_tetriminos_file(char const *file, int argc)
{
	int fd;

	if (argc != 2)
	{
		ft_putstr("usage: ./fillit.h file.txt\n");
		return (-1);
	}
	fd = open(file, O_RDONLY);
	return (fd);
}

static t_double_list	*read_tetriminos_file(int fd, t_double_list *li)
{
	char	*buff;
	int		read_octet;

	if (!(buff = (char *)malloc(sizeof(char) * BUFF_SIZE + 1)))
		return (NULL);
	if (((read_octet = read(fd, buff, BUFF_SIZE))) == (-1))
		return (NULL);
	if (read_octet % 21 != 20 || read_octet == 0 ||
			check_valid_file(buff) == (-1))
	{
		ft_putstr("error\n");
		return (NULL);
	}
	li = get_list_tetriminos(li, buff);
	free(buff);
	return (li);
}

static void				display_final_array(char **final_array)
{
	int line;

	line = 0;
	while (final_array[line])
	{
		ft_putstr(final_array[line]);
		ft_putchar('\n');
		line++;
	}
}

static void				get_coordinates_into_list(t_tetriminos *tmp)
{
	while (tmp)
	{
		coordinates(tmp);
		tmp = tmp->tetris_next;
	}
}

int						main(int argc, char const *argv[])
{
	int				fd;
	t_double_list	*li;
	t_tetriminos	*tmp;
	char			**array;
	char			**final_array;

	li = NULL;
	array = create_and_initialize_final_array_with_dots(2);
	if ((fd = open_tetriminos_file(argv[1], argc)) == (-1))
		return (-1);
	li = read_tetriminos_file(fd, li);
	if (li == NULL)
		return (0);
	tmp = li->begin;
	if (check_hash_touch(tmp) == -1)
	{
		ft_putstr("error\n");
		return (-1);
	}
	get_coordinates_into_list(tmp);
	final_array = put_all(tmp, array, 0, 0);
	display_final_array(final_array);
	free_all(final_array, li->begin);
	return (0);
}
