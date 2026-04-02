# Program name
NAME		= philo

# Compiler and flags
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -pthread -I include

# Source files and object files
SRC_DIR		= src
SRCS		= $(SRC_DIR)/main.c \
			  $(SRC_DIR)/philo.c \
			  $(SRC_DIR)/util.c \
			  $(SRC_DIR)/init.c \
			  $(SRC_DIR)/check_input.c

OBJS		= $(SRCS:.c=.o)

# Rules
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

# Compile .c files into .o files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Remove object files
clean:
	rm -f $(OBJS)

# Remove object files and the executable
fclean: clean
	rm -f $(NAME)

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re