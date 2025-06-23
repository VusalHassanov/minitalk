/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/10 21:46:07 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/10 23:56:12 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

volatile sig_atomic_t	g_ack_received = 0;

void	handle_ack(int sig)
{
	if (sig == SIGUSR1)
		g_ack_received = 1;
}

void	send_char(pid_t server_pid, unsigned char c)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 0b10000000)
			kill(server_pid, SIGUSR1);
		else
			kill(server_pid, SIGUSR2);
		usleep(100);
		c <<= 1;
	}
	while (!g_ack_received)
		pause();
	g_ack_received = 0;
}

void	send_message(pid_t server_pid, char *str)
{
	while (*str)
		send_char(server_pid, *str++);
	send_char(server_pid, '\n');
	send_char(server_pid, '\0');
}

int	main(int argc, char **argv)
{
	struct sigaction	sa;
	pid_t				server_pid;

	if (argc != 3)
	{
		print_error("Incorrect number of entries!\n");
		return (1);
	}
	server_pid = ft_atoi(argv[1]);
	sa.sa_handler = &handle_ack;
	sa.sa_flags = 0;
	sigemptyset(&sa.sa_mask);
	if (sigaction(SIGUSR1, &sa, NULL) == -1)
		print_error("Failed to set handler for SIGUSR1\n");
	if (sigaction(SIGUSR2, &sa, NULL) == -1)
		print_error("Failed to set handler for SIGUSR2\n");
	send_message(server_pid, argv[2]);
	ft_printf("Message successfully received by the server!\n");
	return (0);
}
