#-------------------------------------------

BLACK       =   "\033[0;30m"
GRAY        =   "\033[1;30m"
RED         =   "\033[1;31m"
GREEN       =   "\033[0;32m"
YELLOW      =   "\033[1;33m"
PURPLE      =   "\033[0;35m"
CYAN        =   "\033[1;36m"
WHITE       =   "\033[1;37m"
EOC         =   "\033[0;0m"
LINE_CLEAR  =   "\x1b[1A\x1b[M"

#-------------------------------------------

SRCDIR		=	./srcs
SRC			=	main.c ft_atoi.c

SRC			:=	$(addprefix $(SRCDIR)/, $(SRC))
OBJ			=	$(SRC:.c=.o)

NAME		= philo
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=thread
INC			= -Iincludes

all:		$(NAME)

$(NAME): 	$(OBJ) $(LIBFT)
		@$(CC) $(OBJ) -o $(NAME)
		@echo $(GREEN)"philo made." $(EOC)

%.o: 		%.c
		@$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
		@$(RM) $(OBJ)
		@echo $(GREEN)"philo cleaned." $(EOC)

fclean:		clean
		@$(RM) $(NAME)
		@echo $(GREEN)"philo fcleaned." $(EOC)

re:			fclean all

.PHONY:		clean fclean re
