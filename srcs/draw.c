/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 16:55:12 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/26 19:47:31 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	rotate(t_world *w)
{
	double	olddirx;
	double	oldplanex;
	double	rs;

	rs = 0.05;
	if (g_data.keys.rotright)
	{
		olddirx = w->dir.x;
		w->dir.x = w->dir.x * cos(-(rs)) - w->dir.y * sin(-(rs));
		w->dir.y = olddirx * sin(-(rs)) + w->dir.y * cos(-(rs));
		oldplanex = w->plane.x;
		w->plane.x = w->plane.x * cos(-(rs)) - w->plane.y * sin(-(rs));
		w->plane.y = oldplanex * sin(-(rs)) + w->plane.y * cos(-(rs));
	}
	if (g_data.keys.rotleft == 1)
	{
		olddirx = w->dir.x;
		w->dir.x = w->dir.x * cos((rs)) - w->dir.y * sin((rs));
		w->dir.y = olddirx * sin((rs)) + w->dir.y * cos((rs));
		oldplanex = w->plane.x;
		w->plane.x = w->plane.x * cos((rs)) - w->plane.y * sin((rs));
		w->plane.y = oldplanex * sin((rs)) + w->plane.y * cos((rs));
	}
}

void	left_right(t_world *w, int tempx, int tempy, double movespeed)
{
	if (g_data.keys.left)
	{
		if (!(g_data.map.mat[(int)(w->pos.x - w->dir.y
					* movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x -= w->dir.y * movespeed;
		if (!(g_data.map.mat[(int)(w->pos.x)][(int)(w->pos.y + w->dir.x
			* movespeed)] == '1'))
			w->pos.y += w->dir.x * movespeed;
	}
	if (g_data.keys.right)
	{
		if (!(g_data.map.mat[(int)(w->pos.x + w->dir.y
					* movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x += w->dir.y * movespeed;
		if (!(g_data.map.mat[(int)(w->pos.x)][(int)(w->pos.y - w->dir.x
			* movespeed)] == '1'))
			w->pos.y -= w->dir.x * movespeed;
	}
}

void	up_down(t_world *w, int tempx, int tempy, double movespeed)
{
	if (g_data.keys.up)
	{
		if (!(g_data.map.mat[(int)(w->pos.x + w->dir.x
					* movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x += w->dir.x * movespeed;
		if (!(g_data.map.mat[(int)(w->pos.x)][(int)(w->pos.y + w->dir.y
			* movespeed)] == '1'))
			w->pos.y += w->dir.y * movespeed;
	}
	if (g_data.keys.down)
	{
		if (!(g_data.map.mat[(int)(w->pos.x - w->dir.x
					* movespeed)][(int)(w->pos.y)] == '1'))
			w->pos.x -= w->dir.x * movespeed;
		if (!(g_data.map.mat[(int)w->pos.x][(int)(w->pos.y - w->dir.y
				* movespeed)] == '1'))
			w->pos.y -= w->dir.y * movespeed;
	}
}

void	alter_map(t_world *w)
{
	int		tempx;
	int		tempy;
	double	movespeed;

	tempx = 0;
	tempy = 0;
	movespeed = 0.08;
	up_down(w, tempx, tempy, movespeed);
	left_right(w, tempx, tempy, movespeed);
	rotate(w);
}

void	draw(int x, t_world *w, int texx)
{
	int	y;
	int	color;
	int	wall_height;

	y = 0;
	wall_height = w->drawend - w->drawstart;
	while (y < g_data.scr.image.height)
	{
		if (y < w->drawstart)
			ft_mlx_pixel_put(&g_data.scr.image, x, y, g_data.ceiling);
		if (y >= w->drawstart && y < w->drawend)
		{
			color = ft_mlx_pixel_get(&g_data.current, texx, 1.0
					* (y - w->drawstart) / wall_height * g_data.current.height);
			ft_mlx_pixel_put(&g_data.scr.image, x, y, color);
		}
		if (y >= w->drawend)
			ft_mlx_pixel_put(&g_data.scr.image, x, y, g_data.floor);
		y++;
	}
}
