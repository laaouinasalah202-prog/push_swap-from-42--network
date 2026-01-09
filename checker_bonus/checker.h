/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:06 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/09 08:36:36 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "get_next_line.h"
# include <unistd.h>

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_new(int content);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	pa(t_stack **stack_b, t_stack **stack_a, int i);
void	pb(t_stack **stack_a, t_stack **stack_b, int i);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);
void	rrr(t_stack **stack_a, t_stack **stack_b, int i);
void	ra(t_stack **stack_a, int i);
void	rb(t_stack **stack_b, int i);
void	rr(t_stack **stack_a, t_stack **stack_b, int i);
void	sa(t_stack **stack_a, int i);
void	sb(t_stack **stack_b, int i);
void	ss(t_stack **stack_a, t_stack **stack_b,int i);
int		check_input(int n, char **str);
void	put_to_stack(long *nbrs, t_stack **head, int size);
int		ft_isorted(long *arr, int size);
long	*ft_joinnbr(int ac, char **av);
int		ft_stack_size(t_stack *stack);
int		ft_count_word(int ac, char **av);
char	*get_next_line(int fd);
int		ft_isntsort(t_stack *stack);
void	ft_free(t_stack **stack);

#endif
