/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 13:50:05 by vhasanov          #+#    #+#             */
/*   Updated: 2024/12/06 17:08:59 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	str_len;

	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (start + len > str_len)
		len = str_len - start;
	str_sub = (char *)malloc((len + 1) * sizeof(char));
	if (str_sub == NULL)
		return (NULL);
	ft_memcpy(str_sub, str + start, len);
	str_sub[len] = '\0';
	return (str_sub);
}
