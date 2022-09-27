/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:46 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/27 21:59:34 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_data	g_data;

void	init_data(void)
{
	g_data.player_x = -1.0;
	g_data.player_y = -1.0;
	g_data.spawn = ' ';
	g_data.keys.rotright = 0;
	g_data.keys.rotleft = 0;
	g_data.side = '0';
}

t_file	*init_f(t_file *f)
{
	f = malloc(sizeof(t_file));
	f->idx = 0;
	f->fd_file = 0;
	f->fd = 0;
	return (f);
}

int	main(int argc, char **argv)
{
	t_file	*f;

	init_data();
	f = init_f(f);
	if (!parsing(argc, argv, f) || !read_map(argv[1]))
	{
		free(f);
		return (1);
	}
	g_data.w = malloc(sizeof(t_world));
	g_data.scr.mlx = mlx_init();
	if (!ft_get_sprites(f))
		return (1);
	ft_calculate_resolution();
	init_mlx();
	mlx_hook(g_data.scr.window, 2, 1L << 0, ft_mlx_pressed, &g_data.keys);
	mlx_hook(g_data.scr.window, 3, 1L << 1, ft_mlx_released, &g_data.keys);
	mlx_hook(g_data.scr.window, 17, 1L << 17, ft_mlx_terminate, &g_data.keys);
	ft_init(g_data.w, *f);
	mlx_loop_hook(g_data.scr.mlx, ft_algorithm, f);
	mlx_loop(g_data.scr.mlx);
	free(g_data.w);
	return (0);
}
