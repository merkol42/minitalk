/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 18:30:14 by merkol            #+#    #+#             */
/*   Updated: 2022/04/27 19:05:03 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "mini_talk.h"

static int	g_sent;

char	*palette(char *str)
{
	char	*pid;
	char	*ret;
	int		i;
	int		j;

	i = -1;
	j = -1;
	pid = ft_itoa(getpid());
	ret = (char *)calloc(sizeof(char), ft_strlen(pid) + ft_strlen(str) + 3);
	while (str[++j])
		ret[++i] = str[j];
	j = -1;
	ret[++i] = 2;
	while (pid[++j])
		ret[++i] = pid[j];
	ret[++i] = 3;
	return (ret);
}

void	send_signal(int pid, char *msg)
{
	unsigned int	i;
	int				j;
	unsigned int	bin;

	i = 0;
	j = 0;
	while (msg[i] != '\0')
	{
		bin = 1 << 7;
		while (j < 8)
		{
			if (msg[i] & bin)
				kill(pid, SIGUSR2);
			else
				kill(pid, SIGUSR1);
			usleep(50);
			bin >>= 1;
			j++;
		}
		i++;
		j = 0;
	}
	free(msg);
}

void	handler(int sig)
{
	g_sent = sig;
	ft_printf("Mesaj İletildi");
}

int	main(int ac, char **av)
{
	if (ac != 3)
	{
		ft_printf("[PID] [MESSAGE]");
		exit(EXIT_FAILURE);
	}
	signal(SIGUSR1, handler);
	send_signal(ft_atoi(av[1]), palette(av[2]));
	if (g_sent == 0)
	{
		ft_printf("Mesaj İletilemedi");
		exit(EXIT_FAILURE);
	}
}
