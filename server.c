/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:14:50 by kgraczyk          #+#    #+#             */
/*   Updated: 2024/07/20 13:28:12 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

static void	handle_signal(int sig, siginfo_t *info, void *context)
{
	static char	message[1024];
	static int	bit_count = 0;
	static int	byte_index = 0;

	if (sig == SIGUSR1)
		message[byte_index] |= (0 << bit_count);
	else if (sig == SIGUSR2)
		message[byte_index] |= (1 << bit_count);
	bit_count++;
	if (bit_count == 8)
	{
		bit_count = 0;
		if (message[byte_index] == '\0')
		{
			printf("Received message: %s\n", message);
			memset(message, 0, sizeof(message));
			byte_index = 0;
		}
		else
			byte_index++;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = handle_signal;
	sa.sa_flags = SA_SIGINFO;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	printf("Server PID: %d\n", getpid());
	while (1)
		pause();
	return (0);
}
