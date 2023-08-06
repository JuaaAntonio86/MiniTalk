/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: juanantonio <juanantonio@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/06 11:05:06 by juanantonio       #+#    #+#             */
/*   Updated: 2023/08/06 11:14:00 by juanantonio      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libs/mini_talk.h"

void	bit_handler(int sig)
{
	static int	c = 0;
	static int	num_bit = 0;

	if (sig == SIGUSR1)
		c |= 1 ;
	num_bit++;
	if (num_bit == 8)
	{
		ft_printf("%c", c);
		num_bit = 0;
		c = 0;
	}
	c <<= 1;
}

int	main(void)
{
	ft_printf("Server PID: %d\n", getpid());
	while (1)
	{
		signal(SIGUSR2, bit_handler);
		signal(SIGUSR1, bit_handler);
		pause();
	}
	return (0);
}
