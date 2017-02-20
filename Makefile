# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: orazafin <orazafin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/21 11:58:30 by orazafin          #+#    #+#              #
#    Updated: 2017/02/20 00:50:18 by orazafin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

NAME_LIB = Libft/libft.a

SRCS_FILLIT = src/back_tracking.c\
			src/check_collision.c\
			src/check_hash_touch.c\
			src/check_valid_file.c\
			src/coordinates.c\
			src/create_final_array.c\
			src/free_all.c\
			src/ft_strsplit_fillit.c\
			src/ft_strsub_fillit.c\
			src/hash_into_alpha.c\
			src/initialize_coordinates.c\
			src/list_utilis.c\
			src/main.c\
			src/put_tetris_into_array.c\
			src/tetriminos_utilis.c\

FLAGS += -Wall -Wextra -Werror

OBJS_FILLIT = (SRCS_FILLIT:.c=.o)

all : $(NAME)

$(NAME):
	@echo "compiling fillit..."
	@make -C Libft
	@gcc $(FLAGS) $(SRCS_FILLIT) -o $(NAME) Libft/libft.a  -I ./include
	@echo "fillit done"

clean :
	@echo "deleting objects..."
	@make -C Libft clean
	@echo "deleting done"

fclean : clean
	@echo "deleting library and fillit..."
	@make -C Libft fclean
	@rm -f $(NAME)
	@echo "deleting done"

re : fclean all
