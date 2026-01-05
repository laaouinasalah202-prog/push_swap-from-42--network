/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utile1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:29 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/05 23:22:26 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

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
int	ft_stack_size(t_stack *stack)
{
	int		size;
	t_stack	*temp;

	size = 0;
	temp = stack;
	while (temp)
	{
		temp = temp->next;
		size++;
	}
	return (size);
}
void	put_to_stack(long *nbrs, t_stack **head, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		ft_lstadd_back(head, ft_new(nbrs[i]));
		i++;
	}
}
