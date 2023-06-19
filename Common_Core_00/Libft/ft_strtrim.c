/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abarbieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:02:37 by abarbieu          #+#    #+#             */
/*   Updated: 2023/04/18 15:20:30 by abarbieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_in_set(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t		i;
	size_t		start;
	size_t		end;
	char		*result;

	start = 0;
	while (s1[start] && is_in_set(s1[start], set) == 1)
		start++;
	end = ft_strlen(s1);
	while (is_in_set(s1[end - 1], set) == 1 && end > start)
		end--;
	result = malloc(sizeof(char) * (end - start + 1));
	if (!result)
		return (0);
	i = 0;
	while (start < end)
	{
		result[i] = s1[start];
		i++;
		start++;
	}
	result[i] = '\0';
	return (result);
}
/*
#include <stdio.h>
int main()
{
	printf("%s", ft_strtrim("          ", " "));
}*/