/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:46 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/22 19:52:37 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_data g_data;

int bl(t_file f)
{
    printf("blll\n");
    printf("%s %s %s %s\n" , f.texture[0].id, f.texture[0].file, f.texture[1].id, f.texture[1].file);
    printf("%s %s %s %s\n" , f.texture[2].id, f.texture[2].file, f.texture[3].id, f.texture[3].file);
    //printf("%s %d %d %d %s %d %d %d\n", f.cf[0].id, f.cf[0].rgb.r, f.cf[0].rgb.g, f.cf[0].rgb.b, f.cf[1].id, f.cf[1].rgb.r, f.cf[1].rgb.g, f.cf[1].rgb.b);
    printf("blll\n");
    return(1);
}

void    init_data()
{
    g_data.player_x = -1;
    g_data.player_y = -1;
    g_data.spawn = ' ';
}

int     main(int argc, char **argv)
{
    t_file      *f;
    //t_world     world;
    //t_mlx       mlx;
    init_data();
    f = malloc(sizeof(t_file));
    //parsing(argc, argv, f);
    if(!parsing(argc, argv, f) || !read_map(argv[1]))       //not forget to free
        return (1);
    //bl(*f);
    g_data.scr.mlx = mlx_init();
    if (!ft_get_sprites(f))
        return (1);
    ft_calculate_resolution();
    printf("%d\n", g_data.scr.image.height);
    g_data.time = 0;
    g_data.oldtime = 0;    
    g_data.scr.window = mlx_new_window(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height, "Cub3d");
	g_data.scr.image.ptr = mlx_new_image(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height);
	g_data.scr.image.addr = mlx_get_data_addr(g_data.scr.image.ptr,
			&g_data.scr.image.bpp, &g_data.scr.image.line_len,
			&g_data.scr.image.endian);
    g_data.keys.check = 1;
    mlx_hook(g_data.scr.window, 2, 1L << 0, ft_mlx_pressed, &g_data.keys);
	mlx_hook(g_data.scr.window, 3, 1L << 1, ft_mlx_released, &g_data.keys);
	mlx_hook(g_data.scr.window, 17, 1L << 17, ft_mlx_terminate, &g_data.keys);
	mlx_loop_hook(g_data.scr.mlx, ft_algorithm, f);
	mlx_loop(g_data.scr.mlx);
	return (0);
    //main_algorithm(&world);
    //memory_clear();
}
