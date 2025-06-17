/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vhasanov <vhasanov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/13 06:12:49 by vhasanov          #+#    #+#             */
/*   Updated: 2024/12/13 06:53:46 by vhasanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_word_count(char const *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (s[i] == '\0')
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

void	ft_free(char **strs, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
}

char	**ft_word_str(char const *s, char c, char **strs, int count)
{
	int	end;
	int	start;
	int	i;

	start = 0;
	i = 0;
	while (i < count)
	{
		while (s[start] == c)
			start++;
		end = start;
		while (s[end] != c && s[end] != '\0')
			end++;
		strs[i] = (char *)malloc(sizeof(char) * (end - start + 1));
		if (!strs[i])
		{
			ft_free(strs, i);
			return (NULL);
		}
		ft_strlcpy(strs[i], &s[start], end - start + 1);
		start = end;
		i++;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	int		count;
	char	**strs;

	count = ft_word_count(s, c);
	strs = (char **)malloc(sizeof(char *) * (count + 1));
	if (strs == NULL)
		return (NULL);
	ft_word_str(s, c, strs, count);
	strs[count] = NULL;
	return (strs);
}
