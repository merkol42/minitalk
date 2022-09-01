/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merkol <merkol@42kocaeli.com.tr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 10:28:51 by merkol            #+#    #+#             */
/*   Updated: 2022/04/27 10:28:53 by merkol           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_bitpush(char *str, pid_t pid)
{
	size_t	i;
	size_t	bits;
	size_t	len;

	i = 0;
	len = ft_strlen(str);
	while (i <= len)
	{
		bits = 8;
		while (bits != 0)
		{
			bits--;
			if (((unsigned char)str[i] >> bits & 1) == 1)
				kill(pid, SIGUSR1);
			else if (((unsigned char)str[i] >> bits & 1) == 0)
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	r;

	i = 0;
	pid = 0;
	r = 0;
	if (ac != 3)
		return (write(1, "Usage: ./client [PID][MESSAGE]", 30));
	pid = ft_atoi((const char *)&*av[1]);
	if (!pid)
		return (write(1, "Wrong PID!", 10));
	ft_bitpush(av[2], pid);
	return (1);
}
