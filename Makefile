# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: artprevo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 00:20:03 by artprevo          #+#    #+#              #
#    Updated: 2018/12/09 18:46:15 by tamigore         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIB = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = main.c		\
	  ft_safejoin.c	\
	  parsing.c		\
	  ft_list.c		\
	  ft_array.c

OBJ = $(SRC:.c=.o)

HEADERS = ./incs

all : $(NAME)

$(NAME): $(LIB)
	gcc -o $(NAME) $(addprefix srcs/, $(SRC)) $(LIB) -I $(HEADERS) -L. -lft

clean:
	rm -rdf $(addprefix srcs/, $(OBJ))

fclean: clean
	rm -f $(NAME)

re: fclean all
