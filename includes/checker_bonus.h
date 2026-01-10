/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 22:15:06 by salamoun          #+#    #+#             */
/*   Updated: 2026/01/10 11:15:44 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_strchr1(char *s, char c);
char	*ft_strjoin1(char *s1, char *s2);
char	*ft_strdup1(char *s);
char	*get_next_line(int fd);
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
void	ss(t_stack **stack_a, t_stack **stack_b, int i);
int		check_input(int n, char **str);
int		ft_isorted(long *arr, int size);
long	*ft_joinnbr(int ac, char **av);
int		ft_stack_size(t_stack *stack);
int		ft_count_word(int ac, char **av);
char	*get_next_line(int fd);
void	ft_free(t_stack **stack);
void	put_to_stack(long *nbrs, t_stack **head, int size);

#endif
