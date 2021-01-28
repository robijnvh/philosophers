 # **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robijnvanhouts <robijnvanhouts@student.      +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/11 15:58:48 by robijnvanho   #+#    #+#                  #
#    Updated: 2021/01/14 10:16:22 by robijnvanho   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_one

SRC_DIR = ./srcs

SRC =	main.c threads.c routine.c print.c utils.c utils2.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	@gcc $(FLAGS) -I ./includes/ $(FILES) -o $(NAME)
	@echo "[philo_one] Compiled successfuly! [OK]\n"

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f philo_one

re: fclean all
