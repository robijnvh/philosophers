# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: rvan-hou <rvan-hou@student.42.fr>            +#+                      #
#                                                    +#+                       #
#    Created: 2019/10/28 13:12:30 by rvan-hou      #+#    #+#                  #
#    Updated: 2020/11/03 12:18:39 by rvan-hou      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME  = libft.a

SRCS = 	ft_strdup.c \
		ft_strlen.c \
		ft_strncmp.c \
		ft_atoi.c \
		ft_toupper.c \
		ft_tolower.c \
		ft_isprint.c \
		ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_strchr.c \
		ft_strrchr.c \
		ft_strnstr.c \
		ft_strlcpy.c \
		ft_strlcat.c \
		ft_calloc.c \
		ft_memset.c \
		ft_bzero.c \
		ft_memcpy.c \
		ft_memccpy.c \
		ft_memmove.c \
		ft_memchr.c \
		ft_memcmp.c \
		ft_substr.c \
		ft_strjoin.c \
		ft_itoa.c \
		ft_strtrim.c \
		ft_split.c \
		ft_strmapi.c \
		ft_putchar_fd.c \
		ft_putstr_fd.c \
		ft_putendl_fd.c \
		ft_putnbr_fd.c \
		ft_strcmp.c

LIB = 	ft_strdup.o \
		ft_strlen.o \
		ft_strncmp.o \
		ft_atoi.o \
		ft_toupper.o \
		ft_tolower.o \
		ft_isprint.o \
		ft_isalpha.o \
		ft_isdigit.o \
		ft_isalnum.o \
		ft_isascii.o \
		ft_strchr.o \
		ft_strrchr.o \
		ft_strnstr.o \
		ft_strlcpy.o \
		ft_strlcat.o \
		ft_calloc.o \
		ft_memset.o \
		ft_bzero.o \
		ft_memcpy.o \
		ft_memccpy.o \
		ft_memmove.o \
		ft_memchr.o \
		ft_memcmp.o \
		ft_substr.o \
		ft_strjoin.o \
		ft_itoa.o \
		ft_strtrim.o \
		ft_split.o \
		ft_strmapi.o \
		ft_putchar_fd.o \
		ft_putstr_fd.o \
		ft_putendl_fd.o \
		ft_putnbr_fd.o \
		ft_strcmp.o

BONUS = ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c \

BLIB =	ft_lstnew_bonus.o \
		ft_lstadd_front_bonus.o \
		ft_lstsize_bonus.o \
		ft_lstlast_bonus.o \
		ft_lstadd_back_bonus.o \
		ft_lstdelone_bonus.o \
		ft_lstclear_bonus.o \
		ft_lstiter_bonus.o \
		ft_lstmap_bonus.o \

all: $(NAME)

$(NAME):
	gcc -c -Wall -Wextra -Werror $(SRCS)
	ar rc  $(NAME) $(LIB)

bonus:
	gcc -c -Wall -Wextra -Werror $(BONUS)
	ar rc  $(NAME) $(BLIB)

clean:
	/bin/rm -f $(LIB) $(BLIB)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
