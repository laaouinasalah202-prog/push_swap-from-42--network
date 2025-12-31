/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 20:35:03 by slaaouin          #+#    #+#             */
/*   Updated: 2025/10/18 12:03:38 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	a;

	i = 0;
	while (s[i])
		i++;
	a = (char)c;
	while (i >= 0)
	{
		if (s[i] == a)
			return ((char *)(s + i));
		else
			i--;
	}
	return (0);
}
