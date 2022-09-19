# include "../Includes/cub3d.h"

int	ft_mlx_pressed(int keycode, t_keys *keys)
{
	if (keycode == 65307)
		exit(0);
	if ((keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
		&& keys->check)
	{
		if (keycode == 119)
			keys->up = 1;
		if (keycode == 115)
			keys->down = 1;
		if (keycode == 100)
			keys->right = 1;
		if (keycode == 97)
			keys->left = 1;
		keys->check = 0;
	}
	return (0);
}

int	ft_mlx_released(int keycode, t_keys *keys)
{
	if (keycode == 119 || keycode == 115 || keycode == 100 || keycode == 97)
	{
		if (keycode == 119)
			keys->up = 0;
		if (keycode == 115)
			keys->down = 0;
		if (keycode == 100)
			keys->right = 0;
		if (keycode == 97)
			keys->left = 97;
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