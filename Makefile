# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ltestard <ltestard@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/27 10:57:27 by ltestard          #+#    #+#              #
#    Updated: 2023/06/26 09:55:16 by ltestard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CFLAGS = -Wall -Wextra -Werror
NAME = push_swap

SRC = function_split.c main.c new_pile.c parsing.c radix.c rotate.c \
		index.c swap_push.c tri_five.c tri_three.c utils_split.c utils.c \
		libft.c tri_four.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	gcc $(CFLAGS) -o $(CURDIR)/$(NAME) $(OBJ)

%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
	
clean:
	rm -rf *.o

fclean: clean
	rm -rf $(NAME)

re: fclean all


