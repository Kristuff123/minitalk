/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgraczyk <kgraczyk@student.42warsaw.p      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 13:28:53 by kgraczyk          #+#    #+#             */
/*   Updated: 2024/07/20 13:46:40 by kgraczyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void	send_signal(pid_t server_pid, int sig)
{
	kill(server_pid, sig);
	usleep(100);
}

void	send_bit(pid_t server_pid, char c, int bit_index)
{
	if (bit_index >= 8)
		return ;
	if (c & (1 << bit_index))
		send_signal(server_pid, SIGUSR2);
	else
		send_signal(server_pid, SIGUSR1);
	send_bit(server_pid, c, bit_index + 1);
}

void	send_char(pid_t server_pid, char c)
{
	send_bit(server_pid, c, 0);
}

void	send_string(pid_t server_pid, char *str)
{
	if (*str)
	{
		send_char(server_pid, *str);
		send_string(server_pid, str + 1);
	}
	else
		send_char(server_pid, '\0');
}

int	main(int argc, char *argv[])
{
	pid_t	server_pid;
	char	*message;

	server_pid = atoi(argv[1]);
	if (argc != 3)
	{
		fprintf(stderr, "Usage: %s <server_pid> <string>\n", argv[0]);
		return (1);
	}
	message = argv[2];
	send_string(server_pid, message);
	return (0);
}
