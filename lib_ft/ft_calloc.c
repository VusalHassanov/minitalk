/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:12:13 by vhasanov          #+#    #+#             */
/*   Updated: 2024/12/06 15:23:34 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t n, size_t element_size)
{
	void	*ptr;

	ptr = malloc(n * element_size);
	if (ptr == NULL)
		return (NULL);
	ft_bzero(ptr, element_size * n);
	return (ptr);
}
