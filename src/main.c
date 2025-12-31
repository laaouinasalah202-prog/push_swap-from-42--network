/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-12-15 11:16:17 by slaaouin          #+#    #+#             */
/*   Updated: 2025/12/25 16:23:04 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	radix(t_stack **stack_a, t_stack **stack_b)
{
	int	i;
	int	j;
	int	size;
	int	maxbit;

	size = ft_stack_size(*stack_a);
	maxbit = ft_totalbit(size - 1);
	i = 0;
	while (i < maxbit)
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->index >> i) & 1) == 0)
				pb(stack_a, stack_b);
			else
				ra(stack_a);
			j++;
		}
		while (*stack_b)
			pa(stack_b, stack_a);
		i++;
	}
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
		radix(&stack_a, &stack_b);
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
