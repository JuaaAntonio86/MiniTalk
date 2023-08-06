/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:03:43 by juanantonio       #+#    #+#             */
/*   Updated: 2023/08/07 00:01:02 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mini_talk.h"

void	send_bit(int pid, char *str, size_t len)
{
	int		shift;
	size_t	i;

	i = 0;
	while (i <= len)
	{
		shift = 7;
		while (shift >= 0)
		{
			if ((str[i] >> shift) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			shift--;
			usleep(300);
		}
		i++;
	}
}

int	check_pid(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		pid;

	if (ac == 3)
	{
		if (check_pid(av[1]) == 1)
		{
			ft_printf("\nPlease insert correct PID\n\n");
			return (1);
		}
		pid = ft_atoi(av[1]);
		send_bit(pid, av[2], ft_strlen(av[2]));
	}
	else
	{
		ft_printf("\nPlease insert correct arguments\n\n");
	}
}
