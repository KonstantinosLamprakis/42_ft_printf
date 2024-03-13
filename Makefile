
CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c ft_print_format.c ft_get_hex.c ft_utils_1.c ft_utils_2.c ft_utils_bonus.c ft_utils_2_bonus.c

OBJS = $(SRCS:.c=.o)

HEADER = ft_printf.h

NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp ./libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

$(OBJS): %.o: %.c $(HEADER)
	cc $(CFLAGS) -I $(HEADER) -c $< -o $@

clean:
	$(MAKE) clean -C ./libft
	rm -f $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	rm -f $(NAME)

re: fclean all

.PHONY: re clean fclean all
