/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:55:12 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/26 17:09:26 by symatevo         ###   ########.fr       */
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
	double	olddirx;
	double	oldplanex;
	double	movespeed;
	double 	rotspeed;
	
	movespeed = 0.08;
	rotspeed = 0.1;
	if (g_data.keys.up)
	{
		if (!(g_data.map.mat[(int)(w->pos.x + w->dir.x * movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x += w->dir.x * movespeed;
		if (!(g_data.map.mat[(int)(w->pos.x)][(int)(w->pos.y + w->dir.y * movespeed)] == '1'))
			w->pos.y += w->dir.y * movespeed;
	}
		// if (g_data.spawn == 'N' || g_data.spawn == 'S')
		// 	g_data.player_x  = (int)(g_data.player_x - w->dir.y * movespeed);
		// else
		// 	g_data.player_x  = (int)(g_data.player_x + w->dir.y * movespeed);
		// g_data.player_y = (int)(g_data.player_y + w->dir.x * movespeed);
		//printf("Tempx: %d, tempy: %d\n", tempx, tempy);
		//if (valid_indices(tempx, tempy))
		//{
			// printf("AAA\n");
			// g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
			// // g_data.player_x = tempx;
			// // g_data.player_y = tempy;
			// g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
		//}
	if (g_data.keys.down)
	{
		if (!(g_data.map.mat[(int)(w->pos.x - w->dir.x * movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x -= w->dir.x * movespeed;
		if (!(g_data.map.mat[(int)w->pos.x][(int)(w->pos.y - w->dir.y * movespeed)] =='1'))
			w->pos.y -= w->dir.y * movespeed;
	}
		// if (g_data.spawn == 'N' || g_data.spawn == 'S')
		// 	tempx = (int)(g_data.player_x + w->dir.y * movespeed);
		// else
		// 	tempx = (int)(g_data.player_x - w->dir.y * movespeed);
		// tempy = (int)(g_data.player_y - w->dir.x * movespeed);
		// printf("Tempx: %d, tempy: %d\n", tempx, tempy);
		// if (valid_indices(tempx, tempy))
		// {
		// 	g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
		// 	g_data.player_x = tempx;
		// 	g_data.player_y = tempy;
	// if (g_data.keys.left)
	// {
	// 	if (g_data.spawn == 'N' || g_data.spawn == 'S')
	// 		tempy = (int)(g_data.player_y + w->dir.y * movespeed);
	// 	else
	// 		tempy = (int)(g_data.player_y - w->dir.y * movespeed);
	// 	tempx = (int)(g_data.player_x + w->dir.x * movespeed);
	// 	if (valid_indices(tempx, tempy))
	// 	{
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
	// 		g_data.player_x = tempx;
	// 		g_data.player_y = tempy;
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
	// 	}
	// }
		// 	g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
		// }
	if (g_data.keys.left)
	{
		if (!(g_data.map.mat[(int)(w->pos.x - w->dir.y * movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x -= w->dir.y * movespeed;
		if (!(g_data.map.mat[(int)(w->pos.x)][(int)(w->pos.y + w->dir.x * movespeed)] == '1'))
			w->pos.y += w->dir.x * movespeed;
	}
	if (g_data.keys.right)
	{
		if (!(g_data.map.mat[(int)(w->pos.x + w->dir.y * movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x += w->dir.y * movespeed;
		if (!(g_data.map.mat[(int)(w->pos.x)][(int)(w->pos.y - w->dir.x * movespeed)] == '1'))
			w->pos.y -= w->dir.x * movespeed;
	}
	if (g_data.keys.rotright)
	{
		//printf("mta\n");
		olddirx = w->dir.x;
		w->dir.x = w->dir.x * cos(-(rotspeed)) - w->dir.y * sin(-(rotspeed));
		w->dir.y = olddirx * sin(-(rotspeed)) + w->dir.y * cos(-(rotspeed));
		oldplanex = w->plane.x;
		w->plane.x = w->plane.x * cos(-(rotspeed)) - w->plane.y * sin(-(rotspeed));
		w->plane.y = oldplanex * sin(-(rotspeed)) + w->plane.y * cos(-(rotspeed));
	}
	if (g_data.keys.rotleft == 1)
	{
		//printf("mta\n");
		olddirx = w->dir.x;
		w->dir.x = w->dir.x * cos((rotspeed)) - w->dir.y * sin((rotspeed));
		w->dir.y = olddirx * sin((rotspeed)) + w->dir.y * cos((rotspeed));
		oldplanex = w->plane.x;
		w->plane.x = w->plane.x * cos((rotspeed)) - w->plane.y * sin((rotspeed));
		w->plane.y = oldplanex * sin((rotspeed)) + w->plane.y * cos((rotspeed));
	}
		// if (g_data.spawn == 'N' || g_data.spawn == 'S')
		// 	tempy = (int)(g_data.player_y - w->dir.y * movespeed);
		// else
		// 	tempy = (int)(g_data.player_y + w->dir.y * movespeed);
		// tempx = (int)(g_data.player_x - w->dir.x * movespeed);
		// if (valid_indices(tempx, tempy))
		// {
		// 	g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
		// 	g_data.player_x = tempx;
		// 	g_data.player_y = tempy;
		// 	g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
		// }
	//other direction should be multiplied by rotation matrix
}

void	draw(int x, t_world *w, int texx)
{
	int	y;
	int	color;
	int	wall_height;

	y = 0;

	wall_height = w->drawend - w->drawstart;
	//printf("%f, %f\n", w->dir.x, w->dir.y);
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
			color = ft_mlx_pixel_get(&g_data.current, texx, 1.0 * (y - w->drawstart) / wall_height * g_data.current.height);
			// if (g_data.side == 'N')
			// 	color = ft_mlx_pixel_get(&g_data.north, texx, 1.0 * (y - w->drawstart) / wall_height * g_data.north.height);
			// else if (g_data.side == 'S')
			// 	color = ft_mlx_pixel_get(&g_data.south, texx, 1.0 * (y - w->drawstart) / wall_height * g_data.north.height);
			// else if (g_data.side == 'E')
			// 	color = ft_mlx_pixel_get(&g_data.east, texx, 1.0 * (y - w->drawstart) / wall_height * g_data.north.height);
			// else if (g_data.side == 'W')
			// 	color = ft_mlx_pixel_get(&g_data.west, texx, 1.0 * (y - w->drawstart) / wall_height * g_data.north.height);
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