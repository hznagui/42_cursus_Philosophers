# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hznagui <hznagui@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/21 14:51:10 by hznagui           #+#    #+#              #
#    Updated: 2023/02/27 11:03:47 by hznagui          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

FLAGS = -Wall -Wextra -Werror

SRC_FILE = 	ft_atoi.c \
			main.c \
			lst.c \
			

OBJ_FILE = $(SRC_FILE:.c=.o)


all : $(NAME)

$(NAME) : $(OBJ_FILE) philo.h 
	@cc $(FLAGS) $(OBJ_FILE)  -o $(NAME)
	@echo "--->[mandatory part successfully created ✅]<---"

%.o: %.c philo.h 
	@$(CC) $(FLAGS)  -c $< -o $@

clean :
	@rm -rf $(OBJ_FILE)
	@echo "--->[obj file deleted successfully ✅]<---"

fclean: clean
	@rm -f $(NAME)
	@echo "--->[programs deleted successfully ✅]<---"


re : fclean all