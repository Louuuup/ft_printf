# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:09:39 by yakary            #+#    #+#              #
#    Updated: 2023/03/27 21:27:21 by ycyr-roy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = printer.c \
		printer_1.c \
		lib_ft.c \
		lib_ft1.c \
		ft_printf.c \
		dispatcher.c \
		dispatcher1.c \
		argument_handlers.c

OBJS = $(addprefix $(BIN_DIR)/, $(SRC:.c=.o))
NAME = libftprintf.a
CFLAGS = -Wall -Werror -Wextra -o test
LIBC = ar rc
LIBR = ranlib
RM = rm -f
RM_DIR = rm -rf
BIN_DIR = bin
VPATH = .
all: $(NAME)
$(BIN_DIR)/%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
$(NAME): $(BIN_DIR) $(OBJS)
	$(LIBC) $(NAME) $(OBJS)
	$(LIBR) $(NAME)
$(BIN_DIR):
	mkdir -p $(BIN_DIR)
bonus:
	echo Tu fais quoi la..?
clean:
	$(RM_DIR) $(BIN_DIR)
fclean: clean
	$(RM) $(NAME)
re: fclean all
