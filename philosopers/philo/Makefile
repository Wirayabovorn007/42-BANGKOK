NAME = philo
CC = cc
CFLAGS = -Wall -Wextra -Werror -pthread -I include

SRC_DIR = src
SRCS = main.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/monitor.c \
		$(SRC_DIR)/routine.c \
		$(SRC_DIR)/util.c \
		$(SRC_DIR)/valid_input.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	# FIX 2: Added $(OBJS) to the compilation line
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re