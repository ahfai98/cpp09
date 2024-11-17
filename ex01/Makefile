# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jyap <jyap@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/18 13:40:07 by jyap              #+#    #+#              #
#    Updated: 2024/11/17 15:52:03 by jyap             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_DIR = src/

OBJ_DIR = obj/

INC_DIR = inc/

SRC_FILES	= 	main.cpp \
				RPN.cpp \

OBJ_FILES	= $(SRC_FILES:.cpp=.o)

SRC			=	$(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

NAME = program

CC = c++

CFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_DIR)%.o:$(SRC_DIR)%.cpp
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) -I $(INC_DIR) -o $@ -c $<

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
