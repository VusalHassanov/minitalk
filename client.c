/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 15:29:16 by vhasanov          #+#    #+#             */
/*   Updated: 2025/05/21 16:34:57 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minital.h"

void	send_message(pid_t server_pid, char *str)
{
	int				i;
	int				j;
	unsigned char	c;
	int				bit;
	int				length;

	i = 0;
	length = ft_strlen(str);
	while (i <= length)
	{
		c = str[i];
		j = 7;
		while (j >= 0)
		{
			bit = (c >> j) & 1;
			if (bit == 1)
				kill(server_pid, SIGUSR2);
			else
				kill(server_pid, SIGUSR1);
			usleep(50);
			j--;
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	pid_t server_pid;

	if (argc != 3)
	{
		ft_printf("Incorrect number of entries !\n");
		return (1);
	}

	server_pid = (pid_t)ft_atoi(argv[1]);
	send_message(server_pid, argv[2]);
	return (0);
}