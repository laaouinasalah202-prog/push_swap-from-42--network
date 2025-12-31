/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-25 10:14:29 by slaaouin          #+#    #+#             */
/*   Updated: 2025-12-25 11:18:29 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static int	ft_check_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_word(int ac, char **av)
{
	int	i;
	int	j;
	int	count;

	i = 1;
	count = 0;
	while (i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] != ' ' && (j == 0 || av[i][j - 1] == ' '))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

static void	ft_localfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

long	*ft_joinnbr(int ac, char **av)
{
	long	*result;
	char	**split;
	int		i;
	int		j;
	int		k;

	result = malloc(sizeof(long) * ft_count_word(ac, av));
	if (!result)
		return (NULL);
	i = 1;
	j = 0;
	while (i < ac)
	{
		if (ft_check_space(av[i]))
		{
			k = 0;
			split = ft_split(av[i++], ' ');
			while (split[k])
				result[j++] = ft_atoi(split[k++]);
			ft_localfree(split);
		}
		else
			result[j++] = ft_atoi(av[i++]);
	}
	return (result);
}
