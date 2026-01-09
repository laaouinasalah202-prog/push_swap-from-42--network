/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-17 15:13:50 by slaaouin          #+#    #+#             */
/*   Updated: 2025-12-25 11:16:59 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_stack **stack_from, t_stack **stack_to)
{
	t_stack	*temp;

	if (!stack_from || !(*stack_from))
		return ;
	temp = *stack_from;
	*stack_from = (*stack_from)->next;
	temp->next = *stack_to;
	*stack_to = temp;
}

void	pa(t_stack **stack_b, t_stack **stack_a, int i)
{
	if (!stack_b || !*stack_b)
		return ;
	push(stack_b, stack_a);
	if (i)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b , int i)
{
	if (!stack_a || !*stack_a)
		return ;
	push(stack_a, stack_b);
	if (i)
		write(1, "pb\n", 3);
}
