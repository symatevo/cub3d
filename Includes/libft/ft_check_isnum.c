/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isalpha.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 23:07:18 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/27 18:33:30 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int check_isnum(char *str)
{
    size_t i;

    i = 0;
    while (str[i])
    {
        if (!(ft_isdigit(str[i])))
            return (0);
        i++;
    }
    if (i == ft_strlen(str))
        return (1);
    return (0);
}