/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:55:12 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/25 20:31:20 by aapresya         ###   ########.fr       */
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
	double		tempx;
	double		tempy;
	double		movespeed;
	double 		rotspeed;
	double		olddirx;
	double		oldplanex;
	
	
	tempx = 0;
	tempy = 0;
	movespeed = 0.08;
	rotspeed = 0.1;
	if (g_data.keys.up)
	{
		//tempy = w->pos.x + w->dir.x * movespeed;
		// if (g_data.spawn == 'N' || g_data.spawn == 'S')
			//tempx = g_data.player_x - w->dir.y * movespeed;
		// else
		// 	tempx  = g_data.player_x + w->dir.y * movespeed;
		if (g_data.map.mat[(int)(w->pos.x - w->dir.x * movespeed)][(int)w->pos.y] != '1')
		{
			printf("In the if\n");
			w->pos.x = w->pos.x - w->dir.x * movespeed;
			//g_data.player_y = tempy;
			// g_data.map.mat[(int)w->pos.x][(int)w->pos.y] = '0';
			// g_data.map.mat[(int)w->pos.x][(int)w->pos.y] = g_data.spawn;
		}
	}
	if (g_data.keys.down)
	{
		tempy = g_data.player_y - w->dir.x * movespeed;
		if (g_data.spawn == 'N' || g_data.spawn == 'S')
			tempx = g_data.player_x + w->dir.y * movespeed;
		else
			tempx = g_data.player_x - w->dir.y * movespeed;
		if (g_data.map.mat[(int)tempy][(int)tempx] != '1')
		{
			g_data.player_x = tempx;
			g_data.player_y = tempy;
			g_data.map.mat[(int)g_data.player_y][(int)g_data.player_x] = '0';
			g_data.map.mat[(int)g_data.player_y][(int)g_data.player_x] = g_data.spawn;
		}
	}
	if (g_data.keys.left)
	{
		tempx = g_data.player_x + w->dir.x * movespeed;
		if (g_data.spawn == 'N' || g_data.spawn == 'S')
			tempy = g_data.player_y + w->dir.y * movespeed;
		else
			tempy = g_data.player_y - w->dir.y * movespeed;
		if (g_data.map.mat[(int)tempy][(int)tempx] != '1')
		{
			g_data.player_x = tempx;
			g_data.player_y = tempy;
			g_data.map.mat[(int)g_data.player_y][(int)g_data.player_x] = '0';
			g_data.map.mat[(int)g_data.player_y][(int)g_data.player_x] = g_data.spawn;
		}
	}
	if (g_data.keys.right)
	{
		tempx = g_data.player_x - w->dir.x * movespeed;
		if (g_data.spawn == 'N' || g_data.spawn == 'S')
			tempy = g_data.player_y - w->dir.y * movespeed;
		else
			tempy = g_data.player_y + w->dir.y * movespeed;
		if (g_data.map.mat[(int)tempy][(int)tempx] != '1')
		{
			g_data.player_x = tempx;
			g_data.player_y = tempy;
			g_data.map.mat[(int)g_data.player_y][(int)g_data.player_x] = '0';
			g_data.map.mat[(int)g_data.player_y][(int)g_data.player_x] = g_data.spawn;
		}
	}
	if (g_data.keys.rotright == 1)
	{
		printf("1 Dirx: %f, Diry: %f\n", w->dir.x, w->dir.y);
		printf("1 Planex: %f, Planey:%f\n", w->plane.x, w->plane.y);
		olddirx = w->dir.x;
		w->dir.x = w->dir.x * cos(-rotspeed) - w->dir.y * sin(-rotspeed);
		w->dir.y = olddirx * sin(-rotspeed) + w->dir.y * cos(-rotspeed);
		oldplanex = w->plane.x;
		w->plane.x = w->plane.x * cos(-rotspeed) - w->plane.y * sin(-rotspeed);
		w->plane.y = oldplanex * sin(-rotspeed) + w->plane.y * cos(-rotspeed);
		printf("Dirx: %f, Diry: %f\n", w->dir.x, w->dir.y);
		printf("Planex: %f, Planey:%f\n", w->plane.x, w->plane.y);
	}
	if (g_data.keys.rotleft == 1)
	{
		printf("1 Dirx: %f, Diry: %f\n", w->dir.x, w->dir.y);
		printf("1 Planex: %f, Planey:%f\n", w->plane.x, w->plane.y);
		olddirx = w->dir.x;
		w->dir.x = w->dir.x * cos(rotspeed) - w->dir.y * sin(rotspeed);
		w->dir.y = olddirx * sin(rotspeed) + w->dir.y * cos(rotspeed);
		oldplanex = w->plane.x;
		w->plane.x = w->plane.x * cos(rotspeed) - w->plane.y * sin(rotspeed);
		w->plane.y = oldplanex * sin(rotspeed) + w->plane.y * cos(rotspeed);
		printf("Dirx: %f, Diry: %f\n", w->dir.x, w->dir.y);
		printf("Planex: %f, Planey:%f\n", w->plane.x, w->plane.y);
	}
	
	// if (g_data.keys.down)
	// {
	// 	if (g_data.spawn == 'N' || g_data.spawn == 'S')
	// 		tempx = g_data.player_x + (int)(w->dir.y * movespeed);
	// 	else
	// 		tempx = g_data.player_x - (int)(w->dir.y * movespeed);
	// 	tempy = g_data.player_y - (int)(w->dir.x * movespeed);
	// 	printf("Dirx * movespeed: %f\n", w->dir.x * movespeed);
	// 	//printf("Tempx: %d, tempy: %d\n", tempx, tempy);
	// 	if (valid_indices(tempx, tempy))
	// 	{
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
	// 		g_data.player_x = tempx;
	// 		g_data.player_y = tempy;
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
	// 	}
	// 	printf("Playerx: %d, Playery: %d\n", g_data.player_x, g_data.player_y);
	// 	printf("Tempx: %d, Tempy: %d\n", tempx, tempy);
	// }
	// if (g_data.keys.left)
	// {
	// 	if (g_data.spawn == 'N' || g_data.spawn == 'S')
	// 		tempy = g_data.player_y + (int)(w->dir.y * movespeed);
	// 	else
	// 		tempy = g_data.player_y -(int)( w->dir.y * movespeed);
	// 	tempx = g_data.player_x + (int)(w->dir.x * movespeed);
	// 	if (valid_indices(tempx, tempy))
	// 	{
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
	// 		g_data.player_x = tempx;
	// 		g_data.player_y = tempy;
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
	// 	}
	// }
	// if (g_data.keys.right)
	// {
	// 	if (g_data.spawn == 'N' || g_data.spawn == 'S')
	// 		tempy = g_data.player_y - (int)(w->dir.y * movespeed);
	// 	else
	// 		tempy = g_data.player_y + (int)(w->dir.y * movespeed);
	// 	tempx = g_data.player_x - (int)(w->dir.x * movespeed);
	// 	if (valid_indices(tempx, tempy))
	// 	{
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = '0';
	// 		g_data.player_x = tempx;
	// 		g_data.player_y = tempy;
	// 		g_data.map.mat[g_data.player_y][g_data.player_x] = g_data.spawn;
	// 	}
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
			//color = ft_mlx_pixel_get(&g_data.mat, texx, texy);
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