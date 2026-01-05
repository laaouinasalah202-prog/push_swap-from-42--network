/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utile.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:24 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/05 23:20:31 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void ft_excute(t_stack **stack_a, t_stack **stack_b, char *str)
{
    if(ft_strncmp(str, "sa\n", ft_strlen(str)))
        sa(stack_a);
    if(ft_strncmp(str, "sb\n", ft_strlen(str)))
        sb(stack_b);
    if(ft_strncmp(str, "ss\n", ft_strlen(str)))
        ss(stack_a, stack_b);
    if(ft_strncmp(str, "ra\n", ft_strlen(str)))
        ra(stack_a);
    if(ft_strncmp(str, "rb\n", ft_strlen(str)))
        rb(stack_a);
    if(ft_strncmp(str, "rr\n", ft_strlen(str)))
        rr(stack_a, stack_b);
    if(ft_strncmp(str, "pa\n", ft_strlen(str)))
        pa(stack_a, stack_b);
    if(ft_strncmp(str, "pb\n", ft_strlen(str)))
        pb(stack_b, stack_a);
    if(ft_strncmp(str, "rra\n", ft_strlen(str)))
        rra(stack_a);
    if(ft_strncmp(str, "rrb\n", ft_strlen(str)))
        rrb(stack_b);
    if(ft_strncmp(str, "rrr\n", ft_strlen(str)))
        rrr(stack_a, stack_b);
}
int main(int ac, char **av)
{
    t_stack *stack_a;
    t_stack *stack_b;
    long **numbers;
    int size;
    char *op;

    if(check_input(ac, av) == 1)
    {
        write(1, "Error\n", 6);
        return 1;
    }
    size = ft_count_word(ac, av);
    numbers = ft_joinnbr(ac , av);
    put_to_stack(numbers, &stack_a, size);
    while((op = get_next_line(0)))
        ft_excute(&stack_a, &stack_b, op);
}