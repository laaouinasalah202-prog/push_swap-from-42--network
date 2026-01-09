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

int  push_helper(t_stack **b, t_stack **a, int i)
{
	if ((*b)->index == i)
	{
		pa(b, a, 1);
		return (-1);
	}
	else
		rrb(b, 1);
	return (0);
}

void	ft_back_a(t_stack **a, t_stack **b, int size)
{
	int	i;

	i = size - 1;
	while (i >= 0 && ft_stack_size(*b) > 0)
	{
		size = ft_stack_size(*b);
		if (ft_position(*b, i) > size / 2)
		{
			while (1)
			{
				if(push_helper(b, a, i) == -1)
					break;
			}
		}
		else if (ft_position(*b, i) <= size / 2)
		{
			while (1)
			{
				if ((*b)->index == i)
				{
					pa(b, a, 1);
						break ;
				}
				else
					rb(b, 1);
			}
		}
		i--;
	}
}

void	ft_chunk(t_stack **a, t_stack **b)
{
	int	chunk_size;
	int	size;
	int	i;

	size = ft_stack_size(*a);
	chunk_size = chnk_size(size);
	i = 0;
	while (*a)
	{
		if ((*a)->index <= i)
		{
			pb(a, b, 1);
			rb(b, 1);
			i++;
		}
		else if ((*a)->index <= i + chunk_size)
		{
			pb(a, b, 1);
			i++;
		}
		else
			ra(a, 1);
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
