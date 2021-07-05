NAME = libftprintf.a

SRCS_PATH = srcs/

LIBFT_PATH = libft/

LIBFT_LIB = libft.a

HEADERS_PATH = includes/

SRCS_FILES = ft_eval_conv.c ft_eval_conv2.c ft_printf.c\
	     ft_printf_utils.c ft_printf_utils2.c

SRCS 	= $(addprefix $(SRCS_PATH), $(SRCS_FILES))

OBJS	:= $(SRCS:.c=.o)

CC = gcc

CFLAGS = -Wall -Werror -Wextra

LIBFT_OBJS = $(LIBFT_PATH)*.o

LIBFTMAKE = $(MAKE) -C $(LIBFT_PATH)

all: $(NAME)

$(NAME): $(OBJS) pmake
	ar -rcs $(NAME) $(OBJS) $(LIBFT_OBJS)

pmake:
	$(LIBFTMAKE)

clean:
	make -C $(LIBFT_PATH) clean
	rm -rf $(OBJS)

fclean: clean
		rm -rf $(NAME) $(LIBFT_PATH) $(LIBFT_LIB)

re: fclean all
