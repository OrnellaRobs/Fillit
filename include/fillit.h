/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 00:28:35 by orazafin          #+#    #+#             */
/*   Updated: 2017/02/20 19:01:38 by orazafin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <sys/uio.h>
# include <stdlib.h>

# define BUFF_SIZE 546

# include "../Libft/libft.h"

typedef struct			s_tetriminos
{
	char				**tetriminos;
	struct s_tetriminos *tetris_next;
	struct s_tetriminos *tetris_prev;
	int					start_x;
	int					end_x;
	int					start_y;
	int					end_y;
}						t_tetriminos;

typedef struct			s_double_list
{
	struct s_tetriminos *begin;
	struct s_tetriminos *end;
}						t_double_list;

int						check_collision(char **array, t_tetriminos *tetris,
	int line, int column);
int						check_valid_file(char *buff);
int						check_hash_touch(t_tetriminos *tmp);
int						check_how_many_tetriminos(t_tetriminos *tmp);
char					*ft_strsub_fillit(char const *s, unsigned int start,
	size_t len);
char					**ft_strsplit_fillit(char const *s, char c);
t_tetriminos			*create_new_tetriminos(char **tetriminos);
t_double_list			*push_back_dlist(t_double_list *li, char **data);
t_double_list			*get_list_tetriminos(t_double_list *li, char *buff);
t_double_list			*change_hash_into_alpha(t_double_list *li);
void					initialize_coord(t_tetriminos *tetris);
void					coordinates(t_tetriminos *tetris);
void					free_all(char **final_array, t_tetriminos *tmp);
char					**create_and_initialize_final_array_with_dots(int size);
char					**put_tetris_into_array(t_tetriminos *tetris,
	char **array, int line, int column);
char					**put_all(t_tetriminos *tmp, char	**array, int line,
int column);
#endif
