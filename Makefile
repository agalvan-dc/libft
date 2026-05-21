# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalvan- <agalvan-@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 20:45:57 by agalvan-          #+#    #+#              #
#    Updated: 2026/05/21 15:01:08 by agalvan-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

AR = ar

ARFLAGS = rcs

RMFLAGS = rm -f

NAME = libft.a

SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)


all: $(NAME)

$(NAME): $(OBJECTS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RMFLAGS) $(OBJECTS)

fclean: clean
	$(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re 
