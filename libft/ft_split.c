/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slaaouin <slaaouin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 21:02:40 by slaaouin          #+#    #+#             */
/*   Updated: 2024/10/29 21:02:40 by slaaouin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_word(const char *str, char c)
{
	int	word;
	int	i;

	word = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] && str[i] == c)
			i++;
		if (str[i])
		{
			word++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (word);
}

static char	**ft_free(char **big, int j)
{
	while (j >= 0)
	{
		free(big[j]);
		j--;
	}
	free(big);
	return (NULL);
}

static char	*fft_strdup(const char *str, char c)
{
	char	*result;
	int		i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	result = malloc(i + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (str[i] && str[i] != c)
	{
		result[i] = str[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}

char	**ft_split(char const *s, char c)
{
	char	**big;
	int		j;

	if (!s)
		return (NULL);
	big = (char **)malloc(sizeof(char *) * (ft_count_word(s, c) + 1));
	if (!big)
		return (NULL);
	j = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			big[j] = fft_strdup(s, c);
			if (!big[j])
				return (ft_free(big, j));
			j++;
			while (*s && *s != c)
				s++;
		}
	}
	big[j] = NULL;
	return (big);
}
