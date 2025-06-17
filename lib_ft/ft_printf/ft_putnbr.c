/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 20:00:45 by vhasanov          #+#    #+#             */
/*   Updated: 2025/01/21 17:01:01 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr(long long nbr, char *base, int base_length, char print_type)
{
	size_t	count;

	count = 0;
	if (nbr == 0 && print_type == 'p')
		return (count = ft_putstr("(nil)"));
	if (print_type == 'p' && count == 0)
		count += ft_putstr("0x");
	if (nbr == -2147483648 && (print_type == 'd' || print_type == 'i'))
		return (count = write(1, "-2147483648", 11));
	if ((nbr < 0) && (print_type == 'd' || print_type == 'i'))
	{
		write(1, "-", 1);
		nbr = -nbr;
		count++;
	}
	if (nbr >= base_length)
		count += ft_putnbr(nbr / base_length, base, base_length, 'u');
	write(1, &base[nbr % base_length], 1);
	count++;
	return (count);
}
