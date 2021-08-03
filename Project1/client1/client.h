#ifndef CLIENT_H
# define CLIENT_H
# include <sys/types.h>
# include <signal.h>
# include <unistd.h>
# include <stdlib.h>

void	send_msg(int pid, char *msg);
void	send_sym(int pid, char c);
int		ft_atoi(const char *str);
#endif