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

SRC =	main.c threads.c routine.c print.c

FILES = $(addprefix $(SRC_DIR)/, $(SRC))

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(FILES)
	@echo "Making libft.a"
	@make re -s -C ../libft
	@cp ../libft/libft.a .
	@gcc $(FLAGS) -I ./includes/ $(FILES) libft.a -o $(NAME)
	@echo "[philo_one] Compiled successfuly! [OK]\n"

clean:
	/bin/rm -f *.o
	@make clean -s -C ../libft
	/bin/rm -f libft.a

fclean: clean
	/bin/rm -f philo_one

re: fclean all