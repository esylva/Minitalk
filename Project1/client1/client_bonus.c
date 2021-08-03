#include "client_bonus.h"

int main (int argc, char **argv)
{
	int	pid_serv;
	struct sigaction	client;
	sigset_t set;

	client.sa_flags = SA_SIGINFO;
	sigaddset(&set, SIGUSR1);
	sigaddset(&set, SIGUSR2);
	client.sa_sigaction = handler;
	if (argc != 3)
		write(1, "Incorrect usage.\n./client <server-PID> <message>\n", 50);
	else
	{
		write(1, "Egypt's Forse! It works!\n", 25);
		pid_serv = ft_atoi(argv[1]);
		send_msg(pid_serv, argv[2]);	
		sigaction(SIGUSR1, &client, NULL);
		sigaction(SIGUSR2, &client, NULL);
		usleep(1600);
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

void	handler(int signum, siginfo_t *siginfo, void *ucontext_t)
{
	(void)ucontext_t;
	(void)siginfo;
	if (signum == SIGUSR1)
		write(1, "Transmission successfull!\n", 26);
	else if (signum == SIGUSR2)
		write(1, "Transmission error\n", 19);
	else
		write(1, "Sumthing else\n", 14);
}
