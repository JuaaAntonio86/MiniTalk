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

int	main(int argc, char **argv)
{
	int		pid;
	char	*str;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		str = argv[2];
		send_bit(pid, str, ft_strlen(str));
	}
	else
		ft_printf("\nPlease insert a correct PID and a string to send as argument\n\n");
}


