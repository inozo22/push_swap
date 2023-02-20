# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nimai <nimai@student.42urduliz.com>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/13 13:02:59 by nimai             #+#    #+#              #
#    Updated: 2023/02/20 13:15:45 by nimai            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCDIR = ./src/
SRC = \
		all_free.c \
		cmd1.c \
		cmd2.c \
		errors.c \
		init_ps.c \
		ps_atoi.c \
		push_swap.c \
		quick_sort.c

OBJDIR = ./obj/
OBJ = $(addprefix $(OBJDIR), $(SRC:.c=.o))

LIBDIR = ../libft

#INCLUDE = $(SRCDIR)push_swap.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -g1
#if add "-fsanitize=address", give me "0xbebebebebebebebe" instead of null

all: $(OBJDIR) $(NAME)

$(OBJDIR):
	@mkdir -p $@

$(OBJDIR)%.o : $(SRCDIR)%.c
	@$(CC) -c $(CFLAGS) -o $@ $<

$(NAME): $(OBJ)
	make -C $(LIBDIR)
	$(CC) $(CFLAGS) -I../includes -L $(LIBDIR) -lutil -lft -o $@ $^
#	@ar -rc $(NAME) $^

clean:
	@rm -rf $(OBJDIR)
	@make clean --directory $(LIBDIR)

fclean: clean
	make fclean --directory $(LIBDIR)
	@rm -f $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
