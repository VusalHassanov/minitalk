/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/06/10 17:20:08 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/10 19:34:23 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_minitalk.h"

void	handle_signal(int signum, siginfo_t *info, void *ucontent)
{
	static int				bit_index = 7;
	static unsigned char	c;

	(void)ucontent;
	if (signum == SIGUSR1)
		c |= (1 << bit_index);
	bit_index--;
	if (bit_index < 0)
	{
		ft_putchar_fd(c, STDOUT_FILENO);
		if (kill(info->si_pid, SIGUSR1) == -1)
			print_error("Server failed to send SIGUSR1");
		c = 0;
		bit_index = 7;
	}
}

void	signal_config(void)
{
	struct sigaction	sa_newsig;

	sa_newsig.sa_sigaction = &handle_signal;
	sa_newsig.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &sa_newsig, NULL) == -1)
		print_error("Failed to change SIGUSR1's behavior");
	if (sigaction(SIGUSR2, &sa_newsig, NULL) == -1)
		print_error("Failed to change SIGUSR2's behavior");
}

int	main(void)
{
	ft_printf("SERVER PID = %d\n\n", getpid());
	while (1)
		signal_config();
	return (EXIT_SUCCESS);
}
