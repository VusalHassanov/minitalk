/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:22:12 by vhasanov          #+#    #+#             */
/*   Updated: 2025/06/10 13:49:40 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list arg)
{
	size_t	count;

	count = 0;
	if (c == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (c == 's')
		count += ft_putstr(va_arg(arg, char *));
	else if (c == 'i')
		count += ft_putnbr(va_arg(arg, int), "0123456789", 10, 'i');
	else if (c == 'd')
		count += ft_putnbr(va_arg(arg, int), "0123456789", 10, 'd');
	else if (c == 'u')
		count += ft_putnbr(va_arg(arg, unsigned), "0123456789", 10, 'u');
	else if (c == 'x')
		count += ft_putnbr(va_arg(arg, unsigned), "0123456789abcdef", 16, 'x');
	else if (c == 'X')
		count += ft_putnbr(va_arg(arg, unsigned), "0123456789ABCDEF", 16, 'X');
	else if (c == 'p')
		count += ft_ptr(va_arg(arg, unsigned long long), "0123456789abcdef", 16,
				'p');
	else
		count += ft_putchar(c);
	return (count);
}

int	ft_printf(const char *str, ...)
{
	size_t	count;
	size_t	i;
	va_list	arg;

	count = 0;
	i = 0;
	va_start(arg, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count = count + ft_format(str[i], arg);
		}
		else
			count = count + ft_putchar(str[i]);
		i++;
	}
	return (count);
}
