/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: salamoun <salamoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 11:14:34 by slaaouin          #+#    #+#             */
/*   Updated: 2026/01/05 20:30:45 by salamoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	*ft_bubble_sort(long arr[], long size)
{
	long	i;
	long	j;
	long	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int ft_position(t_stack *stack_b, int i)
{
	if(stack_b == NULL)
		return -1;
	int a;

	a = 0;
	while(stack_b)
	{
		if(stack_b->index == i)
			return a;
		else
			stack_b = stack_b->next;
		a++;
	}
	return -1;
}

int ft_check_element(t_stack *stck, int start, int end)
{
	if(stck == NULL)
		return -1;
	int i;
	i = 0;
	while(stck)
	{
		if((stck->index) >= start && (stck->index <= end))
		{
			return i;
		}
		stck = stck->next;
		i++;
	}
	return -1;
}

int chnk_size(int size)
{
	int chunk_size;

	if (size == 100)
		chunk_size = 15;
	else
		chunk_size = 35;
	return chunk_size;
}