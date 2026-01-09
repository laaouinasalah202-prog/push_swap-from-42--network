/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:24 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/08 18:42:41 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int ft_excute(t_stack **stack_a, t_stack **stack_b, char *str)
{
    if (ft_strncmp(str, "sb\n", ft_strlen(str)) == 0)
        sb(stack_b, 0);
    else if (ft_strncmp(str, "ra\n", ft_strlen(str)) == 0)
        ra(stack_a, 0);
    else if (ft_strncmp(str, "rb\n", ft_strlen(str)) == 0)
        rb(stack_b, 0);
    else if (ft_strncmp(str, "rr\n", ft_strlen(str)) == 0)
        rr(stack_a, stack_b, 0);
    else if (ft_strncmp(str, "pa\n", ft_strlen(str)) == 0)
        pa(stack_b, stack_a, 0);
    else if (ft_strncmp(str, "pb\n", ft_strlen(str)) == 0)
        pb(stack_a, stack_b, 0);
    else if (ft_strncmp(str, "rra\n", ft_strlen(str)) == 0)
        rra(stack_a, 0);
    else if (ft_strncmp(str, "rrb\n", ft_strlen(str)) == 0)
        rrb(stack_b, 0);
    else if(ft_strncmp(str, "rrr\n", ft_strlen(str)) == 0)
        rrr(stack_a, stack_b, 0);
    else if (ft_strncmp(str, "sa\n", ft_strlen(str)) == 0)
        sa(stack_a, 0);
    else if(ft_strncmp(str, "ss\n", ft_strlen(str)) == 0)
        ss(stack_a, stack_b, 0);
    else
    {
        write(2, "Error\n", 6 );
        return -1;
    }
    return 0;
}

int ft_isntsort(t_stack *head)
{
    if (!head || !head->next)
        return 0;

    while (head->next)
    {
        if (head->value > head->next->value)
            return 1;
        head = head->next;
    }
    return 0;
}

void ft_helper(t_stack **stack_a, t_stack **stack_b,long int *numbers, int size)
{
    char *op;

    put_to_stack(numbers, stack_a, size);
    free(numbers);
    op = get_next_line(0);
    while(op)
    {
        if(ft_excute(stack_a, stack_b, op) == -1)
        {
            ft_free(stack_a);
            ft_free(stack_b);
            free(op);
            exit(-1);
        }
        free(op);
        op = get_next_line(0);
    }
    if (ft_isntsort(*stack_a) == 0 && ft_stack_size(*stack_b) == 0)
        write(1, "OK\n", 3);
    else
        write(1, "KO\n", 3);
    ft_free(stack_a);
    ft_free(stack_b);
}

int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    long int *numbers;
    int size;
    if (ac == 1)
	    return 1; 
    stack_a = NULL;
    stack_b = NULL;
    if(check_input(ac, av) == 1)
    {
        write(1, "Error\n", 6);
        return 1;
    }
    size = ft_count_word(ac, av);
    numbers = ft_joinnbr(ac , av);
    ft_helper(&stack_a, &stack_b, numbers, size);
}
