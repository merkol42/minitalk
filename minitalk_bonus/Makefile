NAME_SERVER		= server_bonus
NAME_CLINET		= client_bonus
CC				= gcc
CFLAGS			= -Wall -Werror -Wextra -I.
PRINTF			= libftprintf.a
LIBFT			= libft.a

FILES			= server_bonus.c
OBJS			= $(FILES:%.c=%.o)
FILEC			= client_bonus.c
OBJC			= $(FILEC:%.c=%.o)

all: make-dif $(NAME_SERVER) $(NAME_CLINET) run-server run-client

$(NAME_SERVER): $(OBJS)
	@ar -rcs $(NAME_SERVER) $(OBJS)
$(NAME_CLINET): $(OBJC)
	@ar -rcs $(NAME_CLINET) $(OBJC)

run-server:
	$(CC) -o server_bonus $(NAME_SERVER) $(PRINTF) $(LIBFT)

run-client:
	$(CC) -o client_bonus $(NAME_CLINET) $(PRINTF) $(LIBFT)

make-dif:
	@make -C ft_printf
	@make -C libft
	@mv ft_printf/libftprintf.a .
	@mv libft/libft.a .

clean-dif:
	@make fclean -C ft_printf
	@make fclean -C libft

clean:
	@rm -rf *.o

fclean: clean-dif clean
	@rm -rf $(NAME_CLINET) $(NAME_SERVER) $(PRINTF) $(LIBFT) server_bonus.a client_bonus.a

re : fclean all

.PHONY: all clean fclean re make-dif clean-dif run-server run-client bonus