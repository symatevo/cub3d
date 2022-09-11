/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/27 20:21:19 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/27 20:22:28 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int ft_isspace(int i)
{
	if (i == '\t' || i == '\n' || i == '\r' || i == '\v' || i == '\f' || i == ' ')
		return (1);
	return (0);
}

int word_count(char *str)
{
    int i;
    int w_c;
    int word;

    word = 0;
    i = 0;
    w_c = 0;
    while (str[i] != '\0')
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
    //printf("%s %d", str, w_c);
    return (w_c);
}

char	**ft_words(char *str)
{
	int	i;
    int w;
    int w_c;
    char **ptr;

	i = 0;
    w = 0;
    w_c = word_count(str);
    ptr = malloc(w_c * sizeof(char*));
    w_c = 0;
    while(str[i] != '\0')
    {
        while (ft_isspace(str[i]) && str[i] != '\0')
			i += 1;
        while (!(ft_isspace(str[i])) && str[i] != '\0')
        {
            i++;
            w++;
        }
        ptr[w_c] = ft_substr(str, i-w, i);
        ptr[w_c][w] = '\0';
        w_c++;
        i++;
        w = 0;
    }
	return (ptr);
}