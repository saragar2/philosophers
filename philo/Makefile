NAME = philo
SRCS = main.c ft_isvalidnum.c ft_atoi.c

CFLAGS = -Wall -Wextra -Werror -fsanitize=thread
REMOVE = rm -f
CC = gcc

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(REMOVE) $(OBJS)

fclean: clean
	$(REMOVE) $(NAME)

re: fclean all

