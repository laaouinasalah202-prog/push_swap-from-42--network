/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 11:50:19 by slaaouin          #+#    #+#             */
/*   Updated: 2026/01/10 11:12:19 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_new(int content);
t_stack	*ft_lstnew(int value, int index);
t_stack	*ft_find_smallest(t_stack *stack);
int		ft_stack_size(t_stack *stack);
void	ft_free(t_stack **stack);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
void	ft_lstadd_front(t_stack **lst, t_stack *new);

int		check_input(int n, char **str);
int		ft_count_word(int ac, char **av);
long	*ft_joinnbr(int ac, char **av);
char	**ft_split(char const *s, char c);

int		ft_isorted(long *arr, int size);
long	*ft_bubble_sort(long arr[], long size);
long	*ft_quick_sort(long arr[], long start, long end);
int		ft_totalbit(int a);
void	put_index(long *n, t_stack **stack, int size);
void	put_to_stack(long *nbrs, t_stack **head, int size);
int		chnk_size(int n);
int		ft_check_element(t_stack *stck, int start, int end);
int		ft_position(t_stack *stack_b, int i);

void	sa(t_stack **stack_a, int i);
void	pa(t_stack **stack_b, t_stack **stack_a, int i);
void	pb(t_stack **stack_a, t_stack **stack_b, int i);
void	ra(t_stack **stack_a, int i);
void	rb(t_stack **stack_b, int i);
void	rr(t_stack **stack_a, t_stack **stack_b, int i);
void	rra(t_stack **stack_a, int i);
void	rrb(t_stack **stack_b, int i);

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);

#endif
