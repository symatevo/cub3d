/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:21:19 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/28 15:29:09 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_init_ints(int *first, int *sec, int *third)
{
	*first = 0;
	*sec = 0;
	*third = 0;
}

void	ft_add_int(int *first, int *sec)
{
	*first = *first + 1;
	*sec = *sec + 1;
}

int	ft_isspace(int i)
{
	if (i == '\t' || i == '\n'
		|| i == '\r' || i == '\v' || i == '\f' || i == ' ')
		return (1);
	return (0);
}

int	word_count(char *str)
{
	int	i;
	int	w_c;
	int	word;

	ft_init_ints(&word, &i, &w_c);
	while (str[i] != '\0' && str[i])
	{
		while (ft_isspace(str[i]) && str[i] != '\0')
		{
			i++;
			word = 0;
		}
		while (!(ft_isspace(str[i])) && str[i] != '\0')
		{
			i++;
			word = 1;
		}
		if (word == 1)
			w_c++;
		i++;
	}
	return (w_c);
}

char	**ft_words(char *str)
{
	int		i;
	int		w;
	int		w_c;
	char	**ptr;

	ft_init_ints(&i, &w, &w_c);
	w_c = word_count(str);
	ptr = malloc(w_c * sizeof(char *));
	w_c = 0;
	while (str[i] != '\0')
	{
		while (ft_isspace(str[i]) && str[i] != '\0')
			i += 1;
		while (!(ft_isspace(str[i])) && str[i] != '\0')
			ft_add_int(&i, &w);
		ptr[w_c] = ft_substr(str, i - w, i);
		ptr[w_c][w] = '\0';
		ft_add_int(&w_c, &i);
		w = 0;
	}
	return (ptr);
}
