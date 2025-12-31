/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-16 11:06:16 by slaaouin          #+#    #+#             */
/*   Updated: 2025/10/18 12:47:17 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	result = malloc(len + 1);
	if (!result)
		return (0);
	while (i <= len)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}
