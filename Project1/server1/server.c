#include "server.h"

int	main(void)
{
	struct sigaction	serv;
	
	serv.sa_flags = SA_SIGINFO;
	serv.sa_sigaction = handler;
	write(1, "PID of this server is ", 22);
	ft_putint(getpid(), 1);
	write(1, "\n", 1);
	sigaction(SIGUSR1, &serv, NULL);
	sigaction(SIGUSR2, &serv, NULL);	
	while (1)
		pause ();
	return (0);
}

void	ft_putint(int int_nb, int fd)
{
	if (int_nb < 10)
	{
		ft_putchar_fd(int_nb + '0', fd);
		return ;
	}
	ft_putint(int_nb / 10, fd);
	ft_putchar_fd((int_nb % 10) + '0', fd);
}

void	handler(int signum, siginfo_t *siginfo, void *ucontext_t)
{
	
	static char sym = 0;
	static int	base = 128;
	
	(void)ucontext_t;
	(void)siginfo;
	if (signum == SIGUSR1)
		sym+=base;
	base /=2;
	if (!base)
	{
		ft_putchar_fd(sym, 1);
		if (!sym)
			write(1, "\n", 1);
		sym = 0;
		base = 128;
	}
}

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}