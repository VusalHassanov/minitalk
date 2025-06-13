/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 20:05:24 by vhasanov          #+#    #+#             */
/*   Updated: 2024/12/05 22:00:48 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char	*last_occ;

	last_occ = NULL;
	while (*str != '\0')
	{
		if (*str == (char)c)
			last_occ = str;
		str++;
	}
	if (*str == (char)c)
		last_occ = str;
	return ((char *)last_occ);
}
