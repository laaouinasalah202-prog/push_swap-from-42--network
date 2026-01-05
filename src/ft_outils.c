/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_outils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/18 13:20:38 by slaaouin          #+#    #+#             */
/*   Updated: 2026/01/05 15:27:53 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*ft_new(int content)
{
	t_stack	*result;

	result = malloc(sizeof(t_stack));
	if (!result)
		return (NULL);
	result->value = content;
	result->index = 0;
	result->next = NULL;
	return (result);
}

t_stack	*ft_find_smallest(t_stack *stack)
{
	t_stack		*small;

	small = stack;
	while (stack)
	{
		if (stack->value < small->value)
			small = stack;
		stack = stack->next;
	}
	return (small);
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

void	put_index(long *n, t_stack **stack, int size)
{
	t_stack	*temp;
	int		i;

	temp = *stack;
	while (*stack)
	{
		i = 0;
		while (i < size)
		{
			if (n[i] == (*stack)->value)
			{
				(*stack)->index = i;
				break ;
			}
			i++;
		}
		*stack = (*stack)->next;
	}
	*stack = temp;
}

int chnk_size(int n)
{
	int z;
	
	z = (int)(2 * sqrt(n));
	if(z < 15)
		z = 15;
	return z;
}