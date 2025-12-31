/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-15 14:28:07 by slaaouin          #+#    #+#             */
/*   Updated: 2025/10/22 12:28:19 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;

	s = (unsigned char *)src;
	d = (unsigned char *)dest;
	if (dest == src)
		return (dest);
	if (dest > src)
	{
		while (n)
		{
			n--;
			d[n] = s[n];
		}
	}
	else
	{
		while (n)
		{
			n--;
			*d++ = *s++;
		}
	}
	return (dest);
}
