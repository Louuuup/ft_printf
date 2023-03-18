# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ycyr-roy <ycyr-roy@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/14 15:09:39 by yakary            #+#    #+#              #
#    Updated: 2023/03/17 20:36:37 by ycyr-roy         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
SRC = printer.c \
		printer_1.c \
		ft_atoi.c \
		ft_printf.c

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
