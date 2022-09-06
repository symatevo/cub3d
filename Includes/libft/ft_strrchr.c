/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strrchr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 21:13:54 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/27 17:31:42 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	const char *ptr;

	ptr = str;
	while (*ptr)
	{
		ptr++;
	}
	while (ptr != str - 1)
	{
		if (*ptr == c)
		{
			return ((char *)ptr);
		}
		ptr--;
	}
	ptr = 0;
	return ((char *)ptr);
}
