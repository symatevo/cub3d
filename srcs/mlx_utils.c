/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 18:24:40 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/26 19:08:50 by aapresya         ###   ########.fr       */
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

void	init_mlx(void)
{
	g_data.scr.window = mlx_new_window(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height, "Cub3d");
	g_data.scr.image.ptr = mlx_new_image(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height);
	g_data.scr.image.addr = mlx_get_data_addr(g_data.scr.image.ptr,
			&g_data.scr.image.bpp, &g_data.scr.image.line_len,
			&g_data.scr.image.endian);
	g_data.keys.check = 1;
}
