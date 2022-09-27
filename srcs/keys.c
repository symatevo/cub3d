/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:51:45 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/27 18:16:08 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_mlx_pressed(int keycode, t_keys *keys)
{
	if (keycode == 53)
		exit(0);
	if ((keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0
			|| keycode == 123 || keycode == 124))
	{
		if (keycode == 13)
			keys->up = 1;
		if (keycode == 1)
			keys->down = 1;
		if (keycode == 2)
			keys->right = 1;
		if (keycode == 0)
			keys->left = 1;
		if (keycode == 123)
			keys->rotleft = 1;
		if (keycode == 124)
			keys->rotright = 1;
		keys->check = 0;
	}
	return (0);
}

int	ft_mlx_released(int keycode, t_keys *keys)
{
	if (keycode == 13 || keycode == 1 || keycode == 2 || keycode == 0
		|| keycode == 123 || keycode == 124)
	{
		if (keycode == 13)
			keys->up = 0;
		if (keycode == 1)
			keys->down = 0;
		if (keycode == 2)
			keys->right = 0;
		if (keycode == 0)
			keys->left = 0;
		if (keycode == 123)
			keys->rotleft = 0;
		if (keycode == 124)
			keys->rotright = 0;
		keys->check = 1;
	}
	return (0);
}

int	ft_mlx_terminate(int keycode, t_keys *keys)
{
	(void)keycode;
	(void)keys;
	mlx_destroy_window(g_data.scr.mlx, g_data.scr.window);
	exit(0);
	return (0);
}
