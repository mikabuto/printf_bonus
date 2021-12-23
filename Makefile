NAME = libftprintf.a

SRCS = ft_printf.c ft_printf_utils1.c \
		ft_printf_utils2.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

FLAGS = -Wall -Wextra -Werror
RM = rm -f
CC = cc

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : %.c $(HEADER)
	$(CC) $(FLAGS) -c $< -o $@

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re