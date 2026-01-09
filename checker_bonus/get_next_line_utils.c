/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-11-08 20:27:27 by slaaouin          #+#    #+#             */
/*   Updated: 2026/01/09 08:40:34 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strchr1(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup1(char *s)
{
	char	*result;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s[len])
		len++;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	while (i <= len)
	{
		result[i] = s[i];
		i++;
	}
	return (result);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	char	*result;
	int		i;
	int		j;

	i = 0;
	if (s1)
		i += ft_strlen1(s1);
	i += ft_strlen1(s2) + 1;
	result = malloc(sizeof(char) *  (i + 1));
	if (!result)
		return (NULL);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			result[i] = s1[i];
			i++;
		}
	}
	j = 0;
	while (s2[j])
	{
		result[i] = s2[j];
		i++;
		j++;
	}
	result[i] = '\0';
	return (result);
}
