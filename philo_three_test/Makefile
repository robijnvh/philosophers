# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: robijnvanhouts <robijnvanhouts@student.      +#+                      #
#                                                    +#+                       #
#    Created: 2021/01/11 15:58:48 by robijnvanho   #+#    #+#                  #
#    Updated: 2021/01/28 10:49:14 by robijnvanho   ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = philo_three

SRC_DIR = ./srcs

SRC =	main.c process.c routine.c print.c utils.c libft.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	@gcc $(FLAGS) -I ./includes/ $(FILES) -o $(NAME)
	@echo "[philo_three] Compiled successfuly! [OK]\n"

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f philo_three

re: fclean all