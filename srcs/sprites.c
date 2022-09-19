# include "../Includes/cub3d.h"

// void	ft_calculate_resolution(void)
// {
// 	int	screen_w;
// 	int	screen_h;

// 	mlx_get_screen_size(g_data.scr.mlx, &screen_w, &screen_h);
// 	if (g_data.map->height > g_data.map->width)
// 		g_data.square_size = 0.7 * screen_h / g_data.map->height;
// 	else
// 		g_data.square_size = 0.7 * screen_w / g_data.map->width;
// 	g_data.scr.image.width = g_data.square_size * g_data.map->width;
// 	g_data.scr.image.height = g_data.square_size * g_data.map->height;
// }

void	ft_get_sprites(t_file *f)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (f->texture[i].id[0] == 'N')
		{
			g_data.north.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, f->texture[i].file,
					&g_data.north.width, &g_data.north.height);
			if (!(g_data.north.ptr))
				ft_error("Failed to allocate memory for the north texture.");
			g_data.north.addr = mlx_get_data_addr(g_data.north.ptr,
					&g_data.north.bpp, &g_data.north.line_len, &g_data.north.endian);
		}
		if (f->texture[i].id[0] == 'E')
		{
			g_data.east.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, f->texture[i].file,
					&g_data.east.width, &g_data.east.height);
			if (!(g_data.east.ptr))
				ft_error("Failed to allocate memory for the east texture.");
			g_data.east.addr = mlx_get_data_addr(g_data.east.ptr,
					&g_data.east.bpp, &g_data.east.line_len, &g_data.east.endian);
		}
		if (f->texture[i].id[0] == 'W')
		{
			g_data.west.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, f->texture[i].file,
					&g_data.west.width, &g_data.west.height);
			if (!(g_data.west.ptr))
				ft_error("Failed to allocate memory for the west texture.");
			g_data.west.addr = mlx_get_data_addr(g_data.west.ptr,
					&g_data.west.bpp, &g_data.west.line_len, &g_data.west.endian);
		}
		if (f->texture[i].id[0] == 'S')
		{
			g_data.south.ptr = mlx_xpm_file_to_image(g_data.scr.mlx, f->texture[i].file,
					&g_data.south.width, &g_data.south.height);
			if (!(g_data.south.ptr))
				ft_error("Failed to allocate memory for the south texture.");
			g_data.south.addr = mlx_get_data_addr(g_data.south.ptr,
					&g_data.south.bpp, &g_data.south.line_len, &g_data.south.endian);
		}
		i++;
	}
}