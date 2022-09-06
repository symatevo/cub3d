/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/25 19:38:52 by symatevo          #+#    #+#             */
/*   Updated: 2021/01/25 20:07:12 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	void *p;

	if (!(p = (void *)malloc(size * nitems)))
		return (NULL);
	ft_bzero(p, size * nitems);
	return (p);
}
