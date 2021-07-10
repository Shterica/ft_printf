NAME = libftprintf.a

SRCS_PATH = srcs/

LIBFT_PATH = libft/

LIBFT_LIB = libft.a

HEADERS	= -I includes/ -I libft/

SRCS_FILES = ft_eval_conv.c \
	     ft_eval_conv2.c \
	     ft_eval_flag.c \
		 ft_eval_flag2.c \
	     ft_flag_utils.c \
	     ft_printf.c \
	     ft_printf_utils.c \
	     ft_printf_utils2.c

SRCS 	= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS	:= $(SRCS:.c=.o)

LIBFT	= $(addprefix $(LIBFT_PATH), $(LIBFT_LIB))

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_OBJS = $(LIBFT_PATH)*.o

LIBFTMAKE = $(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJS) pmake
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)
	ranlib $(NAME)

$(SRCS_PATH)%.o: $(SRCS_PATH)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEADERS)

pmake:
	make -C $(LIBFT_PATH)

clean:
	make -C $(LIBFT_PATH) fclean
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME) $(LIBFT_OBJS) $(LIBFT_LIB)

re: fclean all

.PHONY:	all pmake clean fclean re
