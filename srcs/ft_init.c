/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:46 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/26 18:52:50 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_find_pos(double *posx, double *posy)
{
	*posx = g_data.player_y;
	*posy = g_data.player_x;
}

void	ft_fillxy(double *x, double *y, double xv, double yv)
{
	*x = xv;
	*y = yv;
}

void	ft_init(t_world *w, t_file f)
{
	ft_find_pos(&(w->pos.x), &(w->pos.y));
	w->x = (int)w->pos.x;
	w->y = (int)w->pos.y;
	ft_fillxy(&(w->pos.x), &(w->pos.y), w->pos.x + 0.5, w->pos.y + 0.5);
	if (g_data.map.mat[w->x][w->y] == 'N')
	{
		ft_fillxy(&(w->dir.x), &(w->dir.y), -1, 0);
		ft_fillxy(&(w->plane.x), &(w->plane.y), 0.0, 0.66);
	}
	else if (g_data.map.mat[w->x][w->y] == 'S')
	{
		ft_fillxy(&(w->dir.x), &(w->dir.y), 1, 0);
		ft_fillxy(&(w->plane.x), &(w->plane.y), 0.0, -0.66);
	}
	else if (g_data.map.mat[w->x][w->y] == 'W')
	{
		ft_fillxy(&(w->dir.x), &(w->dir.y), 0, -1);
		ft_fillxy(&(w->plane.x), &(w->plane.y), -0.66, 0.0);
	}
	else if (g_data.map.mat[w->x][w->y] == 'E')
	{
		ft_fillxy(&(w->dir.x), &(w->dir.y), 0, 1);
		ft_fillxy(&(w->plane.x), &(w->plane.y), 0.66, 0.0);
	}
}
