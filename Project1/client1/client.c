#include "client.h"

int main (int argc, char **argv)
{
	int	pid_serv;

if (argc != 3)
	write(1, "Incorrect usage.\n./client <server-PID> <message>\n", 50);
else
	{
		pid_serv = ft_atoi(argv[1]);
		send_msg(pid_serv, argv[2]);	
		write(1, "Egypt's Forse! It works!\n", 25);

	}
return (0);
}

void	send_msg(int pid, char *msg) 
{
	int	i;
	
	i = 0;
	while (msg[i])
		send_sym(pid, msg[i++]);
	send_sym(pid, msg[i]);
}

void	send_sym(int pid, char c)
{
	int	base;

	base = 128;
	while (base > 0)
	{
		if (c & base)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		base /= 2;
		usleep(1600);
	}	
}

int	ft_atoi(const char *str)
{
	int	m;
	int	n;

	n = 0;
	m = 0;
	while (((*str >= 9) && (*str <= 13)) || *str == 32)
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
		{
			m++;
		}
		str++;
	}
	while (*str >= 48 && *str <= 57)
	{
		n = n * 10 + (*str - 48);
		str++;
	}
	if (m % 2 == 1)
		n = -n;
	return (n);
}