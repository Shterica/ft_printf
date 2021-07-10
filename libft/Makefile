SRCS	= ft_atoi.c \
	  ft_isdigit.c \
	  ft_strcpy.c \
	  ft_numlen.c \
	  ft_strlen.c \
	  ft_itoa.c\
	  ft_putchar_fd.c \
	  ft_putnbr_hex.c \
	  ft_min.c

OBJ	:= $(patsubst %.c, %.o, $(SRCS))

H	= libft.h

CC	= gcc
CFLAGS	= -Wall -Werror -Wextra

NAME	= libft.a

all: $(NAME)

$(NAME): $(OBJ)
	@ar -rsc $@ $(OBJ)

%.o: %.c $(H)
	$(CC) $(CFLAGS) -o $@ -c $<

clean:
	@rm -rf $(OBJ)

fclean: clean
	@rm -rf $(NAME)

norm:
	@norminette $(SRCS) $(H)

re: fclean all

.PHONY: all clean fclean re norm
