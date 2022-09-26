/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 18:31:02 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/26 18:44:43 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	ft_raydir(t_world *w, int x)
{
	w->camerax = 2 * x / (double)g_data.scr.image.width - 1;
	w->raydir.x = w->dir.x + w->plane.x * w->camerax;
	w->raydir.y = w->dir.y + w->plane.y * w->camerax;
}

void	ft_map_box(t_world *w)
{
	w->map.x = (int)(w->pos.x);
	w->map.y = (int)(w->pos.y);
}

void	ft_deltadist(t_world *w)
{
	w->deltadist.x = fabs(1 / w->raydir.x);
	w->deltadist.y = fabs(1 / w->raydir.y);
	w->hit = 0;
}

void	ft_step_sidedist(t_world *w)
{
	if (w->raydir.x < 0)
	{
		w->step.x = -1;
		w->sidedist.x = (w->pos.x - w->map.x) * w->deltadist.x;
	}
	else
	{
		w->step.x = 1;
		w->sidedist.x = (w->map.x + 1.0 - w->pos.x) * w->deltadist.x;
	}
	if (w->raydir.y < 0)
	{
		w->step.y = -1;
		w->sidedist.y = (w->pos.y - w->map.y) * w->deltadist.y;
	}
	else
	{
		w->step.y = 1;
		w->sidedist.y = (w->map.y + 1.0 - w->pos.y) * w->deltadist.y;
	}
}
