/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:53:05 by vhasanov          #+#    #+#             */
/*   Updated: 2025/01/21 18:42:20 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putstr(char *str)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	if (str == NULL)
		return (count = write(1, "(null)", 6));
	while (str[i])
	{
		count = count + ft_putchar(str[i]);
		i++;
	}
	return (count);
}
