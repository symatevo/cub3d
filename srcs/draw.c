/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:55:12 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/23 18:44:16 by aapresya         ###   ########.fr       */
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
	int		tempx;
	int		tempy;
	double	frametime;
	double	movespeed;
	double 	rotspeed;

	g_data.oldtime = g_data.time;
	g_data.time = get_time();
	frametime = (g_data.time - g_data.oldtime) / 1000;		//converts to seconds
	//printf("Time now: %Lf\n, frametime: %f\n", g_data.time, frametime);
	movespeed = frametime * 5.0;
	rotspeed = frametime * 3.0;
	if (g_data.keys.up)
	{
		//printf("Key Up\n");
		tempx = (int)(w->dir.y * movespeed + g_data.player_x);
		tempy = (int)(g_data.player_y - w->dir.x * movespeed);
		//printf("Tempx: %d, tempy: %d\n", tempx, tempy);
		if (valid_indices(tempx, tempy))
		{
			g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
			g_data.player_x = tempx;
			g_data.player_y = tempy;
			g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
		}
	}
	if (g_data.keys.down)
	{
		tempx = (int)(g_data.player_x - w->dir.y * movespeed);
		tempy = (int)(g_data.player_y + w->dir.x * movespeed);
		if (valid_indices(tempx, tempy))
		{
			g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
			g_data.player_x = tempx;
			g_data.player_y = tempy;
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

	wall_height = w->drawend - w->drawstart;
	printf("%f, %f\n", w->dir.x, w->dir.y);
	//printf("On x: %d, Drawstart: %d, drawend: %d\n", x, w->drawstart, w->drawend);
	while (y < g_data.scr.image.height)
	{
		if (y < w->drawstart)
			ft_mlx_pixel_put(&g_data.scr.image, x, y, g_data.ceiling);
		if (y >= w->drawstart && y < w->drawend)
		{
			//float texy;
			//texy = (y - w->drawstart) / wall_height * g_data.north.height;
			//color = ft_mlx_pixel_get(&g_data.north, texx, texy);
			color = ft_mlx_pixel_get(&g_data.north, texx, 1.0 * (y - w->drawstart) / wall_height * g_data.north.height);
			//printf("texx: %d, texy: %d\n", texx, (y - w->drawstart) / wall_height * g_data.north.height);
			//printf("%d, %d\n", g_data.north.height, wall_height);
			//printf("%d, %d\n", w->drawstart, y);
			//printf("%d", y);
			//color = g_data.temp_color;
			ft_mlx_pixel_put(&g_data.scr.image, x, y, color);
		}
		if (y >=  w->drawend)
			ft_mlx_pixel_put(&g_data.scr.image, x, y, g_data.floor);
		y++;
	}
	// while (y < w->drawstart)
	// {
	// 	ft_mlx_pixel_put(&g_data.scr.image, x, y, g_data.ceiling);
	// 	y++;
	// }
	// printf("On x: %d, Drawstart: %d, drawend: %d, y: %d\n", x, w->drawstart, w->drawend, y);
	// while (y <= w->drawend)
	// {
	// 	//color = ft_mlx_pixel_get(&g_data.north, texx, (w->drawend - y) / wall_height * g_data.north.height);
	// 	color = g_data.temp_color;
	// 	ft_mlx_pixel_put(&g_data.scr.image, x, y, color);
	// 	y++;
	// }
	// while (y < g_data.scr.image.height)
	// {
	// 	ft_mlx_pixel_put(&g_data.scr.image, x, y, g_data.floor);
	// 	y++;	
	// }
}