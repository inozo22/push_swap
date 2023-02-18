# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:02:59 by nimai             #+#    #+#              #
#    Updated: 2023/02/18 12:28:42 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g1
#if add "-fsanitize=address", give me "0xbebebebebebebebe" instead of null

NAME = push_swap

RM = rm -f

#First of all, I have to compile library, later main program#
LIBFT_PATH = libft

LIBS = $(LIBFT_PATH)/libft.a

SRC_PATH = src

SRC = \
		all_free.c \
		cmd1.c \
		cmd2.c \
		cmd3.c \
		errors.c \
		init_ps.c \
		main.c \
		ps_atoi.c \
		push_swap.c \
		quick_sort.c

INCLUDE = $(SRC_PATH)/push_swap.h

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	@$(CC) $(CFLAGS) -c $(SRC)
	@make -C $(LIBFT_PATH)
	@mv $(LIBS) $(NAME)
	@ar rcs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)
	@make clean --directory $(LIBFT_PATH)

fclean: clean
	make fclean --directory $(LIBFT_PATH)
	@$(RM) $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
