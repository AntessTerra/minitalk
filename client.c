/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbartosi <jbartosi@student.42prague.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 10:37:08 by jbartosi          #+#    #+#             */
/*   Updated: 2023/02/25 13:47:19 by jbartosi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static void	send_str(int pid, char *str)
{
	unsigned char	c;
	int				i;

	while (*str)
	{
		i = 8;
		c = *str++;
		while (i--)
		{
			if ((c >> i) & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(500);
		}
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(500);
	}
}

static void	sig_recieved(int sig)
{
	if (sig == SIGUSR1)
		signal(SIGUSR1, sig_recieved);
	else if (sig == SIGUSR2)
	{
		ft_printf("MESSAGE recieved!\n");
		exit(0);
	}
}

int	main(int argc, char **argv)
{
	signal(SIGUSR1, sig_recieved);
	signal(SIGUSR2, sig_recieved);
	if (argc != 3 || (ft_atoi(argv[1]) < 1) || (ft_strlen(argv[2]) < 1))
		ft_printf("ERROR on clients side!!!\n");
	else
		send_str(ft_atoi(argv[1]), argv[2]);
}
