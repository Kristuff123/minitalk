# Main Makefile

# Variables
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = libft
FT_PRINTF_DIR = ft_printf
LIBFT = $(LIBFT_DIR)/libft.a
FT_PRINTF = $(FT_PRINTF_DIR)/libftprintf.a
SERVER = server
CLIENT = client
SRCS = server.c client.c

# Default target
all: $(LIBFT) $(FT_PRINTF) $(SERVER) $(CLIENT)

# Compile libft.a
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Compile libftprintf.a (depends on libft.a)
$(FT_PRINTF): $(LIBFT)
	$(MAKE) -C $(FT_PRINTF_DIR)

# Compile server
$(SERVER): server.o $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) server.o -o $(SERVER) -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft 

# Compile client
$(CLIENT): client.o $(LIBFT) $(FT_PRINTF)
	$(CC) $(CFLAGS) client.o -o $(CLIENT) -L$(FT_PRINTF_DIR) -lftprintf -L$(LIBFT_DIR) -lft 

# Compile object files
server.o: server.c
	$(CC) $(CFLAGS) -c server.c

client.o: client.c
	$(CC) $(CFLAGS) -c client.c

# Clean up object files and executables
clean:
	rm -f *.o
	$(MAKE) -C $(LIBFT_DIR) clean
	$(MAKE) -C $(FT_PRINTF_DIR) clean

fclean: clean
	rm -f $(LIBFT) $(FT_PRINTF) $(SERVER) $(CLIENT)
	$(MAKE) -C $(LIBFT_DIR) fclean
	$(MAKE) -C $(FT_PRINTF_DIR) fclean

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re

