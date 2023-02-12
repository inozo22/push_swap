# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 13:19:10 by nimai             #+#    #+#              #
#    Updated: 2023/02/11 09:14:46 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g1
#if add "-fsanitize=address", give me "0xbebebebebebebebe" instead of null

NAME = push_swap

RM = rm -f

LIBFT_PATH = libft

LIBS = $(LIBFT_PATH)/libft.a

SRC = ft_printf.c ft_printf_utils.c 

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
