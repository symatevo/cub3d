/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strlcpy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 20:05:55 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/27 17:25:41 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*osrc;
	size_t	nleft;

	osrc = (char *)src;
	nleft = size;
	if (nleft != 0)
	{
		while (--nleft != 0)
		{
			if ((*dest++ = *src++) == '\0')
				break ;
		}
	}
	if (nleft == 0)
	{
		if (size != 0)
			*dest = '\0';
		while (*src++)
			;
	}
	return (src - osrc - 1);
}
