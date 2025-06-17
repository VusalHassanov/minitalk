/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 17:12:49 by vhasanov          #+#    #+#             */
/*   Updated: 2025/01/21 18:47:06 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_ptr(unsigned long long nbr, char *base,
		unsigned long long base_length, char print_type)
{
	size_t	count;

	count = 0;
	if (nbr == 0 && print_type == 'p')
		return (count = ft_putstr("(nil)"));
	if (count == 0 && print_type == 'p')
		count += ft_putstr("0x");
	if (nbr >= base_length)
		count += ft_putnbr(nbr / base_length, base, base_length, 'u');
	write(1, &base[nbr % base_length], 1);
	count++;
	return (count);
}
