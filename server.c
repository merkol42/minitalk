/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:29:12 by merkol            #+#    #+#             */
/*   Updated: 2022/04/27 10:29:13 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_print_signal(int sig)
{
	static unsigned char	c;
	static size_t			size;

	if (sig == SIGUSR2)
		sig = 0;
	else if (sig == SIGUSR1)
		sig = 1;
	if (c == 0 && size == 0)
		size = 8;
	size--;
	c += (sig & 1) << size;
	if (size == 0)
	{
		if (!c)
		{
			ft_putchar_fd('\n', 1);
		}
		ft_putchar_fd(c, 1);
		size = 8;
		c = 0;
	}
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, ft_print_signal);
	signal(SIGUSR2, ft_print_signal);
	while (1)
		pause();
}
