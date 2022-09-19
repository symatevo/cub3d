/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:45:46 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/11 18:54:16 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

t_data g_data;

int bl(t_file f)
{
    printf("blll\n");
    printf("%s %d %s %d\n" , f.texture[0].id, f.texture[0].file_name, f.texture[1].id, f.texture[1].file_name);
    printf("%s %d %s %d\n" , f.texture[2].id, f.texture[2].file_name, f.texture[3].id, f.texture[3].file_name);
    printf("%s %d %d %d %s %d %d %d\n", f.cf[0].id, f.cf[0].rgb.r, f.cf[0].rgb.g, f.cf[0].rgb.b, f.cf[1].id, f.cf[1].rgb.r, f.cf[1].rgb.g, f.cf[1].rgb.b);
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
    //bl(*f);

    read_map(argv[1]);
    g_data.scr.mlx = mlx_init();
    ft_get_sprites(f);
    //ft_calculate_resolution();    //Do we need this? oof
    g_data.scr.window = mlx_new_window(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height, "Cub3d");  //image width and image height are not initialized yet
	g_data.scr.image.ptr = mlx_new_image(g_data.scr.mlx,
			g_data.scr.image.width, g_data.scr.image.height);
	g_data.scr.image.addr = mlx_get_data_addr(g_data.scr.image.ptr,
			&g_data.scr.image.bpp, &g_data.scr.image.line_len,
			&g_data.scr.image.endian);
    mlx_hook(g_data.scr.window, 2, 1L << 0, ft_mlx_pressed, &g_data.keys);
	mlx_hook(g_data.scr.window, 3, 1L << 1, ft_mlx_released, &g_data.keys);
	mlx_hook(g_data.scr.window, 17, 1L << 17, ft_mlx_terminate, &g_data.keys);
	//mlx_loop_hook(g_data.scr.mlx, ft_render, NULL);
	mlx_loop(g_data.scr.mlx);
	//return (0);
    //main_algorithm(&world);
    //memory_clear();
    return (0);
}
