NAME = philo
SRCS = activities.c threads.c main.c init.c time.c one_philo.c utils.c

CFLAGS = -Wall -Wextra -Werror -pthread -g3 -fsanitize=thread
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

