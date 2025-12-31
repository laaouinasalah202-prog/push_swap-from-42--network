/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 13:37:31 by slaaouin          #+#    #+#             */
/*   Updated: 2025-12-22 11:17:21 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	ft_reverse_rotate(t_stack **stack)
{
	t_stack	*temp;
	t_stack	*temp2;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	temp2 = NULL;
	temp = *stack;
	while ((*stack)->next != NULL)
	{
		temp2 = *stack;
		*stack = (*stack)->next;
	}
	temp2->next = NULL;
	(*stack)->next = temp;
}

void	rra(t_stack **stack_a)
{
	ft_reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b)
{
	ft_reverse_rotate(stack_b);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_reverse_rotate(stack_a);
	ft_reverse_rotate(stack_b);
}
