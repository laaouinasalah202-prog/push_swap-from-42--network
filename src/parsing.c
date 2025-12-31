/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-17 14:10:47 by slaaouin          #+#    #+#             */
/*   Updated: 2025/12/27 14:21:48 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_isnumber(char *str)
{
	int	i;
	int	n;

	n = 1;
	i = 0;
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] && str[i + 1] != ' ')
		{
			n = 1;
			i++;
		}
		else if ((str[i] == '-' || str[i] == '+') && n == 1)
		{
			n = 0;
			i++;
		}
		else if (str[i] >= '0' && str[i] <= '9')
		{
			i++;
		}
		else
			return (1);
	}
	return (0);
}

static int	ft_check_double(int n, long *str)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		if (str[i] > 2147483647 || str[i] < -2147483648)
			return (1);
		while (j < n)
		{
			if (str[i] - str[j] == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_input(int n, char **str)
{
	int		i;
	int		size;
	long	*numbers;

	i = 1;
	size = ft_count_word(n, str);
	while (str[i] && i < n)
	{
		if (ft_isnumber(str[i]) || (str[i][0] == '\0'))
			return (1);
		i++;
	}
	numbers = ft_joinnbr(n, str);
	if (ft_check_double(size, numbers))
	{
		free(numbers);
		return (1);
	}
	free(numbers);
	return (0);
}
