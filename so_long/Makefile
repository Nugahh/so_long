# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fwong <fwong@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/25 15:53:23 by fwong             #+#    #+#              #
#    Updated: 2022/07/25 01:37:48 by fwong            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	so_long

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror -MMD -MP -I./includes -g3
# -Lminilibx-linux -lmlx -lX11 -lXext -MMD -MP -I./includes -g3

LIB		=	-Llibft/ -lft -Lminilibx-linux -lmlx -lX11 -lXext

SRCS	= 	parsing.c\
			check_map.c\
			check_path.c\
			utils.c\
			init_map.c\
			move.c\
			utils2.c\
			so_long.c\

OBJS	:=	${addprefix ./obj/,${SRCS:%.c=%.o}}

DEP		=	$(addprefix ./obj/,$(OBJS:%.o=%.d))

all: ${NAME}

-include $(DEP)

./obj/%.o: ./src/*/%.c
	@mkdir -p $(@D)
	@make -C minilibx-linux
	$(CC) $(CFLAGS) -o $@ -c $<

${NAME}: ${OBJS} ./libft/libft.a
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIB)
	
./libft/libft.a:
	make $(@F) -C $(@D)

clean:
	rm -rf obj/
	rm -f ${OBJS}
	make $@ -C ./libft/

fclean: 
	rm -rf obj/
	rm -f ${NAME}
	make $@ -C libft

re:	fclean all

.PHONY: all clean fclean re
