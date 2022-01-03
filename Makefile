NAME = libftprintf.a

SRCS = printme.c utils1.c utils2.c printf_bonus.c \
		hex.c

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

bonus : re

clean :
	$(RM) $(OBJS)

fclean :	clean
	$(RM) $(NAME)

re :	fclean all

.PHONY : all clean fclean re