# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: agalvan- <agalvan-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/02/17 20:45:57 by agalvan-          #+#    #+#              #
#    Updated: 2026/02/18 15:10:10 by agalvan          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

CFLAGS = -Wall -Werror -Wextra -g

AR = ar

ARFLAGS = rcs

RMFLAGS = rm -f

NAME = libft.a

SOURCES = $(filter-out %_bonus.c, $(wildcard *.c))
OBJECTS = $(SOURCES:.c=.o)

SOURCES_BONUS = $(wildcard *_bonus.c)
OBJECTS_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS) 
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

bonus: $(OBJECTS) $(OBJECTS_BONUS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJECTS) $(OBJECTS_BONUS)

clean:
	$(RMFLAGS) $(OBJECTS) $(OBJECTS_BONUS)

fclean: clean
	$(RMFLAGS) $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus
