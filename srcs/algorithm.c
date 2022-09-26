/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:52:24 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/26 18:41:53 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_dda(t_world *w)
{
	while (w->hit == 0)
	{
		if (w->sidedist.x < w->sidedist.y)
		{
			w->sidedist.x = w->sidedist.x + w->deltadist.x;
			w->map.x = w->map.x + w->step.x;
			w->side = 0;
		}
		else
		{
			w->sidedist.y = w->sidedist.y + w->deltadist.y;
			w->map.y = w->map.y + w->step.y;
			w->side = 1;
		}
		if (g_data.map.mat[w->map.x][w->map.y] == '1')
			w->hit = 1;
	}
	return (0);
}

void	ft_perpwalldist(t_world *w)
{
	if (w->side == 0)
		w->perpwalldist = (w->map.x - w->pos.x
				+ (1 - w->step.x) / 2) / w->raydir.x;
	else
		w->perpwalldist = (w->map.y - w->pos.y
				+ (1 - w->step.y) / 2) / w->raydir.y;
}

void	start_end_pixel(t_world *w)
{
	w->lineheight = (int)(g_data.scr.image.height / w->perpwalldist);
	w->drawstart = -(w->lineheight) / 2 + g_data.scr.image.height / 2;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = (w->lineheight) / 2 + g_data.scr.image.height / 2;
	if (w->drawend < 0)
		w->drawend = g_data.scr.image.height - 1;
	g_data.side = '0';
	if (w->side == 0)
	{
		if (w->raydir.x < 0)
			g_data.current = g_data.north;
		else if (w->raydir.x > 0)
			g_data.current = g_data.south;
	}
	else if (w-> side == 1)
	{
		if (w->raydir.y < 0)
			g_data.current = g_data.west;
		else if (w->raydir.y > 0)
			g_data.current = g_data.east;
	}
}

int	ft_texx(t_world *w)
{
	int		texx;
	double	wallx;

	if (w->side == 0)
		wallx = w->pos.y + w->perpwalldist * w->raydir.y;
	else
		wallx = w->pos.x + w->perpwalldist * w->raydir.x;
	wallx -= floor((wallx));
	texx = (int)(wallx * (double)g_data.north.width);
	if (w->side == 0 && w->raydir.x > 0)
		texx = g_data.current.width - texx - 1;
	if (w->side == 1 && w->raydir.y < 0)
		texx = g_data.current.width - texx - 1;
	return (texx);
}

int	ft_algorithm(t_file *f)
{
	int	y;
	int	x;
	int	texx;

	x = 0;
	alter_map(g_data.w);
	while (x < g_data.scr.image.width)
	{
		y = 0;
		ft_raydir(g_data.w, x);
		ft_map_box(g_data.w);
		ft_deltadist(g_data.w);
		ft_step_sidedist(g_data.w);
		ft_dda(g_data.w);
		ft_perpwalldist(g_data.w);
		start_end_pixel(g_data.w);
		texx = ft_texx(g_data.w);
		draw(x, g_data.w, texx);
		x++;
	}
	mlx_put_image_to_window(g_data.scr.mlx, g_data.scr.window,
		g_data.scr.image.ptr, 0, 0);
	mlx_string_put(g_data.scr.mlx, g_data.scr.window, 25, 25, 0x00FF0000, " ");
	mlx_do_sync(g_data.scr.mlx);
	return (0);
}
