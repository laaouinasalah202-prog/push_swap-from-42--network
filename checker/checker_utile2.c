/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utile2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:31 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/05 23:27:15 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"
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

void	pa(t_stack **stack_b, t_stack **stack_a)
{
	if (!stack_b || !*stack_b)
		return ;
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	if (!stack_a || !*stack_a)
		return ;
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
