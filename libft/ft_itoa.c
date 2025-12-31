/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-10-16 15:48:14 by slaaouin          #+#    #+#             */
/*   Updated: 2025/10/18 12:38:58 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:02:40 by slaaouin          #+#    #+#             */
/*   Updated: 2024/10/29 21:02:40 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

static int	ft_len2(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_str(int len, unsigned int number, int is_negative)
{
	char	*result;

	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	len--;
	while (len >= is_negative)
	{
		result[len] = number % 10 + '0';
		number /= 10;
		len--;
	}
	if (is_negative)
		result[0] = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	char			*result;
	int				len;
	unsigned int	number;
	int				is_negative;

	if (n == 0)
	{
		result = malloc(2);
		if (!result)
			return (NULL);
		result[0] = '0';
		result[1] = '\0';
		return (result);
	}
	len = ft_len2(n);
	is_negative = 0;
	if (n < 0)
	{
		number = -n;
		is_negative = 1;
	}
	else
		number = n;
	return (ft_str(len, number, is_negative));
}
