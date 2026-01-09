/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-14 01:23:02 by slaaouin          #+#    #+#             */
/*   Updated: 2025/12/27 14:22:14 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack)
{
	if ((*stack)->next == NULL)
		return ;
	if ((*stack)->value > ((*stack)->next)->value)
		sa(stack, 1);
}

void	sort_three(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->value;
	b = (*stack)->next->value;
	c = (*stack)->next->next->value;
	if (a > b && b < c && a < c)
		sa(stack, 1);
	else if (a > b && b > c && a > c)
	{
		sa(stack, 1);
		rra(stack, 1);
	}
	else if (a > b && b < c && a > c)
		ra(stack, 1);
	else if (a < b && b > c && a < c)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else if (a < b && b > c && a > c)
		rra(stack, 1);
}

void	sort_ff(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		i;
	t_stack	*small;

	i = 0;
	while (i++ < 2)
	{
		small = ft_find_smallest(*stack_a);
		if (small->index > size / 2)
			while (*stack_a != small)
				rra(stack_a, 1);
		else
			while (*stack_a != small)
				ra(stack_a, 1);
		pb(stack_a, stack_b, 1);
	}
	sort_three(stack_a);
	while (*stack_b)
		pa(stack_b, stack_a, 1);
}

void	sort_foor(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*temp;
	t_stack	*small;

	temp = *stack_a;
	small = temp;
	while (temp)
	{
		if (temp->value < small->value)
			small = temp;
		temp = temp->next;
	}
	while (*stack_a != small)
		ra(stack_a, 1);
	pb(stack_a, stack_b, 1);
	sort_three(stack_a);
	pa(stack_b, stack_a, 1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 2)
		sort_two(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else if (size == 4)
		sort_foor(stack_a, stack_b);
	else
		sort_ff(stack_a, stack_b, size);
}
