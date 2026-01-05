/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 11:16:17 by slaaouin          #+#    #+#             */
/*   Updated: 2026/01/05 21:24:25 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// int position_cost(t_stack *satck, int value)
// {
// 	int size;
// 	int pos;
// 	int cost;

// 	size = ft_stack_size(stack);
// 	pos = ft_position(stack, value);

// 	if(pos > size / 2)
// 		cost = size - pos;
// 	else
// 		cost = pos;

// 	return cost;

// }

void ft_back_a(t_stack **a, t_stack **b,int size)
{
	int i;
	int pos;
	
	i = size - 1;
	while(i >= 0 && ft_stack_size(*b) > 0)
	{
		size = ft_stack_size(*b);
		pos = ft_position(*b, i);
		if(pos > size / 2) 
		{
			while(1)
			{
				if((*b)->index == i)
				{
					pa(b, a);
						break;
				}
				else
					rrb(b);
			}
		}
		else if (pos <= size/2)
		{
			while(1)
			{
				if((*b)->index == i)
				{
					pa(b, a);
						break;
				}
				else
					rb(b);
			}
		}
		i--;
	}
}


void ft_chunk(t_stack **a, t_stack **b)
{
	int chunk_size;
	int size;
	int i, end, start, z;
	size = ft_stack_size(*a);
	if(size == 100)
		chunk_size = 20;
	else if(size == 500)
		chunk_size = 50;
	else
		chunk_size = chnk_size(size);
	i = 0;
	while(i < size)
	{
		start = i;
		end = i + chunk_size;
		while(ft_check_element(*a, start, end) != -1)
		{
			if(((*a)->index) >= start && ((*a)->index <= end))
			{
				pb(a, b);
			    if ((*b)->index > (start + end) / 2) // optimization
        			rb(b); 
			}
			else
			{
				z = ft_check_element(*a, start, end);
				if (z == -1)
					break;
				else if(z > (ft_stack_size(*a)/2))
					rra(a);
				else
					ra(a);
			}
				
		}
		i += chunk_size;
	}
	ft_back_a(a, b, size);
}

static void	ft_push_swap(int ac, char **av, long *stack)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		size;

	stack_a = NULL;
	stack_b = NULL;
	size = ft_count_word(ac, av);
	put_to_stack(stack, &stack_a, size);
	if (size <= 5)
		sort_small(&stack_a, &stack_b, size);
	else
	{
		stack = ft_bubble_sort(stack, size);
		put_index(stack, &stack_a, size);
		ft_chunk(&stack_a, &stack_b);
	}
	free(stack);
	ft_free(&stack_a);
	ft_free(&stack_b);
}

int	main(int ac, char **av)
{
	long	*stack;
	int		size;

	size = ft_count_word(ac, av);
	if (ac >= 2)
	{
		if (check_input(ac, av))
		{
			write(1, "Error\n", 6);
			return (0);
		}
		stack = ft_joinnbr(ac, av);
		if (!ft_isorted(stack, size))
		{
			free(stack);
			return (0);
		}
		ft_push_swap(ac, av, stack);
	}
	return (0);
}
