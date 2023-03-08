# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 14:51:10 by hznagui           #+#    #+#              #
#    Updated: 2023/03/08 14:18:55 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror 

SRC_FILE = 	tolls2.c \
			main.c \
			lst.c \
			tolls1.c \

COLOUR_GREEN=\033[1;32m

COLOUR_RED=\033[1;31m
	

OBJ_FILE = $(SRC_FILE:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ_FILE) philo.h 
	@cc $(FLAGS) $(OBJ_FILE)  -o $(NAME)
	@echo  "$(COLOUR_GREEN)--->[mandatory part successfully created ✅]<---"

%.o: %.c philo.h 
	@$(CC) $(FLAGS)  -c $< -o $@

clean :
	@rm -rf $(OBJ_FILE)
	@echo "$(COLOUR_RED)--->[obj file deleted successfully ✅]<---"

fclean: clean
	@rm -f $(NAME)
	@echo "$(COLOUR_RED)--->[programs deleted successfully ✅]<---"


re : fclean all