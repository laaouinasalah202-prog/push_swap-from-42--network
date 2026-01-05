/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:06 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/05 22:44:24 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  CHECKER_H
#define CHECKER_H
#include "../libft/libft.h"
#include "../get_next_line/get_next_line.h"
typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

void	pa(t_stack **stack_b, t_stack **stack_a);
void	pb(t_stack **stack_a, t_stack **stack_b);
void	rra(t_stack **stack_a);
void	rrb(t_stack **stack_b);
void	rrr(t_stack **stack_a, t_stack **stack_b);
void	ra(t_stack **stack_a);
void	rb(t_stack **stack_b);
void	rr(t_stack **stack_a, t_stack **stack_b);
void	sa(t_stack **stack_a);
void	sb(t_stack **stack_b);
void	ss(t_stack **stack_a, t_stack **stack_b);
int	check_input(int n, char **str);
void	put_to_stack(long *nbrs, t_stack **head, int size);
long	ft_isorted(long *arr, int size);
long	*ft_joinnbr(int ac, char **av);
int	ft_stack_size(t_stack *stack);
int	ft_count_word(int ac, char **av);

#endif