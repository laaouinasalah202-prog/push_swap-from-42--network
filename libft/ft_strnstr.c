/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 21:46:01 by slaaouin          #+#    #+#             */
/*   Updated: 2025/10/19 16:56:11 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	l;
	size_t	i;
	size_t	j;

	j = 0;
	l = 0;
	i = 0;
	while (little[l] != '\0')
		l++;
	if (l == 0)
		return ((char *)big);
	while (big[j] != '\0' && j < len)
	{
		i = 0;
		while ((j + i) < len && big[j + i] != '\0'
			&& big[j + i] == little[i])
			i++;
		if (i == l)
			return ((char *)big + j);
		j++;
	}
	return (NULL);
}
