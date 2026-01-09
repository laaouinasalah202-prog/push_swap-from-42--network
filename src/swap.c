/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-25 11:14:23 by slaaouin          #+#    #+#             */
/*   Updated: 2025-12-25 11:14:23 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = (*stack)->next;
	(*stack)->next = temp->next;
	temp->next = (*stack);
	(*stack) = temp;
}

void	sa(t_stack **stack_a, int i)
{
	swap(stack_a);
	if(i)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int i)
{
	swap(stack_b);
	if(i)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int i)
{
	swap(stack_a);
	swap(stack_b);
	if(i)
		write(1, "ss\n", 3);
}
