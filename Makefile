NAME = libftprintf.a

CFLAGS = -Wall -Wextra -Werror -MD

CC = gcc

SRC = ft_itoa.c			\
	  ft_itoa_16.c		\
	  ft_printf.c		\
	  ft_strlen.c		\
	  ft_ultoa_16.c		\
	  ft_use_flags_1.c	\
	  ft_use_flags_2.c	\
	  ft_utoa.c			\
	  ft_atoi.c			\
	  ft_strchr.c		\
	  ft_strdup.c		\
	  ft_itoa_16_to_lower.c \
	  ft_ultoa_16_to_upper.c

HEADER = ft_printf.h

OBJ = $(SRC:%.c=%.o)

all: $(NAME)

bonus: re

$(NAME): $(OBJ) $(HEADER)
		 @ar -r $(NAME) $(OBJ)

%.o : %.c
		 @$(CC) $(CFLAGS) -c $< -o $@

clean:
		 @rm -rf $(OBJ)

fclean:	 clean
		 @rm -rf $(NAME)

re:		 fclean all

.PHONY: clean fclean all re
