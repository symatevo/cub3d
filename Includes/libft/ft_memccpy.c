/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 13:33:34 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/20 16:01:07 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			idx;

	idx = 0;
	while (idx < n)
	{
		*((unsigned char *)dest + idx) = *((unsigned char *)src + idx);
		if (*((unsigned char *)src + idx) == (unsigned char)c)
		{
			return (dest + idx + 1);
			break ;
		}
		idx++;
	}
	return (NULL);
}
