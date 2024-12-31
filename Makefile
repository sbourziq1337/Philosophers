SORS = philo.c helper.c check_routine.c handle_philosopher.c nor.c create_philo.c
OBJC=$(SORS:.c=.o)
NAME = philo
RM = rm -f
CC = cc #-fsanitize=thread -g3
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)


$(NAME): $(OBJC) 
	$(CC) $(CFLAGS) -o $(NAME) $^

clean:
	$(RM) $(OBJC)

fclean: clean
	$(RM) $(NAME)

re: fclean all