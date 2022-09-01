/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:30:24 by merkol            #+#    #+#             */
/*   Updated: 2022/04/27 18:30:25 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	g_pid;

void	solution(char c)
{
	static int	i;
	static int	j;

	if (c == 2)
		i++;
	if (c != 2 && i == 0)
		write(1, &c, 1);
	if (i > 0 && c != 2 && c != 3)
		j = j * 10 + c - '0';
	if (c == 3)
	{
		g_pid = j;
		i = 0;
		j = 0;
	}
}

static void	handler(int signum)
{
	static int				i;
	static unsigned char	x;

	x <<= 1;
	i++;
	if (signum == SIGUSR2)
		x |= 1;
	if (i == 8)
	{
		solution(x);
		i = 0;
		x = 0;
	}
	if (g_pid > 0)
	{
		ft_putchar_fd('\n', 1);
		kill(g_pid, SIGUSR1);
		g_pid = 0;
	}
}

int	main(void)
{
	ft_printf("PID : %d\n", getpid());
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	while (1)
		pause();
	return (0);
}
