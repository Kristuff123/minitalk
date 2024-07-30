NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRC = ft_printf.c
OBJ = $(SRC:.c=.o)
LIBFT_PATH = libft
LIBFT = $(LIBFT_PATH)/libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LIBFT_PATH)
	@echo "Creating $(NAME)..."
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo "$(NAME) created successfully!"
	@cp $(LIBFT) .

$(OBJ): $(SRC)
	@echo "Compiling $<..."
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	@echo "Cleaning object files..."
	@rm -f $(OBJ)
	@echo "Object files cleaned!"

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	@echo "Cleaning $(NAME)..."
	@rm -f $(NAME) ./libft.a
	@echo "$(NAME) cleaned!"

re: fclean all

.PHONY: all clean fclean re

