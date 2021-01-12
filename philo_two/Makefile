# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robijnvanhouts <robijnvanhouts@student.      +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/08 12:30:55 by robijnvanho   #+#    #+#                  #
#    Updated: 2021/01/08 12:31:21 by robijnvanho   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_two

SRC_DIR = ./srcs

SRC =	main.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	@gcc $(FLAGS) -I ./includes/ $(FILES) -o $(NAME)
	@echo "[philo_two] Compiled successfuly! [OK]\n"

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f philo_two

re: fclean all