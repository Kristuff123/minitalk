# ft_printf/Makefile

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I../libft
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)
NAME = libftprintf.a
LIBFT = ../libft/libft.a

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	ar rcs $(NAME) $(OBJS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

