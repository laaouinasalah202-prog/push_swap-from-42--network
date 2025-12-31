/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-16 13:31:52 by slaaouin          #+#    #+#             */
/*   Updated: 2025/10/24 13:51:47 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	set_checker(const char *set, char c)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	size;

	if (!s1 || !set)
		return (NULL);
	while (*s1 && set_checker(set, *s1))
		s1++;
	size = ft_strlen(s1);
	while (size > 0 && set_checker(set, s1[size - 1]))
		size--;
	res = malloc(size + 1);
	if (!res)
		return (NULL);
	ft_strlcpy(res, s1, size + 1);
	return (res);
}
