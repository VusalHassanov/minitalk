/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 23:55:56 by vhasanov          #+#    #+#             */
/*   Updated: 2024/12/06 01:00:41 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str1, const char *str2, size_t len)
{
	size_t	i;

	if (*str2 == '\0')
		return ((char *)str1);
	while ((len > 0) && *str1 != '\0')
	{
		i = 0;
		while (i < len && *(str1 + i) == *(str2 + i))
		{
			i++;
			if (*(str2 + i) == '\0')
				return ((char *)str1);
		}
		str1++;
		len--;
	}
	return (NULL);
}
