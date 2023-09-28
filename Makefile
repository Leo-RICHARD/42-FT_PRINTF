SRCS		= ft_printf.c flags.c flags_utils.c print.c print_utils.c utils.c 

OBJS		= $(SRCS:.c=.o)

NAME		= libftprintf.a

CC			= cc

RM			= rm -f

CFLAGS		= -Wall -Wextra -Werror

.c.o:		ft_printf.h
			$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS) ft_printf.h
			ar rcs $(NAME) $?

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
