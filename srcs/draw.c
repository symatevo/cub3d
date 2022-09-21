/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:55:12 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/21 15:43:09 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

// int	ft_render(void)
// {
// 	// alter the map?
// 	// draw the frame
// 	mlx_put_image_to_window(g_data.scr.mlx, g_data.scr.window, g_data.scr.image.ptr, 0, 0);
// 	mlx_string_put(g_data.scr.mlx, g_data.scr.window, 25, 25, 0x00FF0000, " ");
// 	mlx_do_sync(g_data.scr.mlx);
// 	// return (0);
// }

int	valid_indices(int x, int y)
{
	if (x < 0 || x >= g_data.map.width || y < 0 || y >= g_data.map.height)
		return (0);
	if (g_data.map.mat[y][x] != '0')
		return (0);
	return (1);
}

void	alter_map(t_world *w)
{
	if (g_data.keys.up)
	{
		if (valid_indices(w->dir.x + g_data.player_x, g_data.player_y - w->dir.y))
		{
			g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
			g_data.player_x = w->dir.x + g_data.player_x;
			g_data.player_y = g_data.player_y - w->dir.y;
			g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
		}
	}
	if (g_data.keys.down)
	{
		if (valid_indices(g_data.player_x - w->dir.x, g_data.player_y + w->dir.y))
		{
			g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
			g_data.player_x = g_data.player_x - w->dir.x;
			g_data.player_y = g_data.player_y + w->dir.y;
			g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
		}
	}
	//other direction should be multiplied by rotation matrix
}

void	draw(int x, t_world *w, int texx)
{
	int	y;
	int	color;
	int	wall_height;

	y = 0;

	wall_height = w->drawend - w->drawstart + 1;
	while (y < w->drawend)
		ft_mlx_pixel_put(&g_data.scr.image, x, y++, g_data.ceiling);
	while (y <= w->drawstart)
	{
		color = ft_mlx_pixel_get(&g_data.north, texx, y / wall_height * g_data.north.height);
		ft_mlx_pixel_put(&g_data.scr.image, x, y, color);
		y++;
	}
	while (y <= g_data.scr.image.height)
		ft_mlx_pixel_put(&g_data.scr.image, x, y++, g_data.floor);
}