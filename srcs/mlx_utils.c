/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:24:40 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/20 18:43:42 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_mlx_pixel_put(t_img *image, int x, int y, int color)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	*(unsigned int *)dst = color;
}

unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y)
{
	char	*dst;

	dst = image->addr + (y * image->line_len + x * (image->bpp / 8));
	return (*(unsigned int *)dst);
}