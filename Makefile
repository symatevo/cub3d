# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/28 21:36:19 by aapresya          #+#    #+#              #
#    Updated: 2022/09/11 16:51:22 by aapresya         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= cub3d

MLX		= -Lmlx -lmlx -framework OpenGL -framework AppKit -lm
SRCS	= $(wildcard srcs/*.c)
OBJS	= ${SRCS:.c=.o}
CC		= gcc
CFLAGS	= -g -ggdb3#-O3 -Wall -Wextra -Werror
RM		= rm -rf

all: $(NAME)

${NAME}: ${OBJS}
	@echo [cub3d] Compiling mlx...
	@$(MAKE) -C ./mlx
	@echo [cub3d] Compiling libft...
	@$(MAKE) -C Includes/libft
	@mv mlx/libmlx.dylib .
	@echo [cub3d] Compiling cub3d...
	@${CC} ${OBJS} ${CFLAGS} ${MLX} Includes/libft/libft.a libmlx.dylib -o ${NAME}
	@echo [cub3d] cub3d successfully compiled. Run ./cub3d \*.cub to read from a map. 

clean:
	@$(MAKE) -C mlx clean
	@$(MAKE) -C Includes/libft fclean
	@${RM} ${OBJS}

fclean: clean
	@${RM} ${NAME}
	@${RM} libmlx.dylib

norme:
	@norminette -R CheckForbiddenSourceHeader *.c *.h libft/*.c libft/*.h
	
bonus: all

re: fclean all

.PHONY: clean fclean re all bonus
