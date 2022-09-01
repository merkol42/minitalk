NAME1 = server

NAME2 = client

PRINTF = ft_printf/libftprintf.a

BONUS1 = server_bonus

BONUS2 = client_bonus

all :
	@make -C libft
	@make -C ft_printf
	@gcc -Wall -Wextra -Werror server.c libft/libft.a $(PRINTF) -o $(NAME1)
	@gcc -Wall -Wextra -Werror client.c libft/libft.a $(PRINTF) -o $(NAME2)

bonus :
	@make -C libft
	@make -C ft_printf
	@gcc -Wall -Wextra -Werror server_bonus.c libft/libft.a -o $(BONUS1)
	@gcc -Wall -Wextra -Werror client_bonus.c libft/libft.a -o $(BONUS2)

clean :
	@make clean -C libft
	@make clean -C ft_printf
	@rm -rf client.o server.o 

fclean : clean
	@make fclean -C libft
	@make fclean -C ft_printf
	@rm -rf $(NAME1) $(NAME2) 

re : fclean all

.PHONY: fclean clean re bonus all
