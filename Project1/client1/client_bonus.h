#ifndef CLIENT_BONUS_H
# define CLIENT_BONUS_H
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>


void	send_msg(int pid, char *msg);
void	send_sym(int pid, char c);
int		ft_atoi(const char *str);
void	handler(int signum, siginfo_t *siginfo, void *ucontext_t);
#endif