/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/31 16:47:07 by kgraczyk          #+#    #+#             */
/*   Updated: 2024/08/02 18:01:58 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "ft_printf/ft_printf.h"

pid_t	g_client_pid = 0;

void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	bit_count = 0;

	(void)context;
	g_client_pid = info->si_pid;
	if (sig == SIGUSR1)
		c |= (0 << bit_count);
	else if (sig == SIGUSR2)
		c |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		write(1, &c, 1);
		c = 0;
		bit_count = 0;
	}
	kill(g_client_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handle_signal;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
