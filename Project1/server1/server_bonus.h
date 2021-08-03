#ifndef SERVER_BONUS_H
# define SERVER_BONUS_H
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>

void	ft_putint(int int_nb, int fd);
void	ft_putchar_fd(char c, int fd);
void	handler(int signum, siginfo_t *siginfo, void *ucontext_t);
void	ft_end(siginfo_t *siginfo);
#endif