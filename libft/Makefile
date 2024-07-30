NAME = libft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_absolut.c ft_strlen.c ft_putnbr.c ft_put_hexadecimal.c ft_put_adress.c ft_putstr.c ft_putchar.c ft_putnbr_fd.c ft_putbase_fd.c ft_strchr.c ft_put_unsigned.c ft_atoi.c
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "Creating $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) created successfully!"

%.o: %.c
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "Cleaning object files..."
	@rm -f $(OBJ)
	@echo "Object files cleaned!"

fclean: clean
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME)
	@echo "$(NAME) cleaned!"

re: fclean all

.PHONY: all clean fclean re

