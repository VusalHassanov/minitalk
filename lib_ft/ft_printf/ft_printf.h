/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 19:47:05 by vhasanov          #+#    #+#             */
/*   Updated: 2025/01/21 18:43:26 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

size_t	ft_putchar(char c);
size_t	ft_putstr(char *str);
size_t	ft_putnbr(long long nbr, char *base, int base_length, char print_type);
int		ft_printf(const char *str, ...);
size_t	ft_ptr(unsigned long long nbr, char *base,
			unsigned long long base_length, char print_type);

#endif
