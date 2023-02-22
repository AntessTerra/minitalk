/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:37:07 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/22 16:21:39 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	print_str(int sig, siginfo_t *info, void *something)
{
	static int	pid;

	(void)something;
	pid = info->si_pid;
	*g_box.c |= (sig == SIGUSR1);
	if (++*g_box.i == 8)
	{
		*g_box.i = 0;
		ft_printf("%c", *g_box.c);
		if (!*g_box.c)
		{
			kill(pid, SIGUSR1);
			return ;
		}
		*g_box.c = 0;
	}
	else
		*g_box.c <<= 1;
}

int	main(void)
{
	struct sigaction	sa;
	unsigned char		c;
	int					i;

	i = 0;
	c = 0;
	g_box.c = &c;
	g_box.i = &i;
	ft_printf("Server PID: %d\n", getpid());
	sa.sa_sigaction = print_str;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		sleep(1);
	return (0);
}
