#include "../Includes/cub3d.h"

int     is_pos(char c)
{
    if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
        return (1);
    return (0);
}

void     ft_find_pos(double *posx, double *posy)
{
	*posx = g_data.player_y;
	*posy = g_data.player_x;
	//g_data.player_x += 0.5;
	//g_data.player_y += 0.5;
}

void    ft_fillxy(double *x, double *y, double xv, double yv)
{
    *x = xv;
    *y = yv;
}
// int	valid(t_world w)
// {
// 	if (g_data.inited == 0)
// 	{
// 		g_data.inited = 1;
// 		printf("Inside if\n");
// 		return (1);
// 	}
// 	printf("Please\n");
// 	if (w.dir.x != 1 || w.dir.x != -1 || w.dir.x != 0)
// 		return (0);
// 	if (w.dir.y != 1 || w.dir.y != -1 || w.dir.y != 0)
// 		return (0);
// 	if (w.plane.x != 0 || w.plane.x != 0.66)
// 		return (0);
// 	if (w.plane.y != 0 || w.plane.y != 0.66)
// 		return (0);
// 	return (1);	/////
// }

int     ft_init(t_world *w, t_file f)
{
    int x;
    int y;

    ft_find_pos(&(w->pos.x), &(w->pos.y));
    x = (int)w->pos.x;
    y = (int)w->pos.y;
	w->pos.x += 0.5;
	w->pos.y += 0.5;
	printf("%c", g_data.map.mat[x][y]);
    if (g_data.map.mat[x][y] == 'N')
	{
        ft_fillxy(&(w->dir.x), &(w->dir.y), -1, 0);
		ft_fillxy(&(w->plane.x), &(w->plane.y), 0.0, 0.66);
	}
    else if (g_data.map.mat[x][y] == 'S')
	{
        ft_fillxy(&(w->dir.x), &(w->dir.y), 1, 0);
		ft_fillxy(&(w->plane.x), &(w->plane.y), 0.0, -0.66);
	}
    else if (g_data.map.mat[x][y] == 'W')
	{
        ft_fillxy(&(w->dir.x), &(w->dir.y), 0, -1);
		ft_fillxy(&(w->plane.x), &(w->plane.y), -0.66, 0.0);

	}
    else if (g_data.map.mat[x][y] == 'E')
	{
        ft_fillxy(&(w->dir.x), &(w->dir.y), 0, 1);
    	ft_fillxy(&(w->plane.x), &(w->plane.y), 0.66, 0.0);
	}
	w->time = 0;
	w->oldtime = 0;
    return (0);
}

int     ft_init_move(t_world *w, t_file f)
{
    int x;
    int y;

    ft_find_pos(&(w->pos.x), &(w->pos.y));
    x = (int)w->pos.x;
    y = (int)w->pos.y;
	w->pos.x += 0.5;
	w->pos.y += 0.5;
	//printf("%c", g_data.map.mat[x][y]);
    // if (g_data.map.mat[x][y] == 'N')
	// {
    //     ft_fillxy(&(w->dir.x), &(w->dir.y), -1, 0);
	// 	ft_fillxy(&(w->plane.x), &(w->plane.y), 0.0, 0.66);
	// }
    // else if (g_data.map.mat[x][y] == 'S')
	// {
    //     ft_fillxy(&(w->dir.x), &(w->dir.y), 1, 0);
	// 	ft_fillxy(&(w->plane.x), &(w->plane.y), 0.0, -0.66);
	// }
    // else if (g_data.map.mat[x][y] == 'W')
	// {
    //     ft_fillxy(&(w->dir.x), &(w->dir.y), 0, -1);
	// 	ft_fillxy(&(w->plane.x), &(w->plane.y), -0.66, 0.0);

	// }
    // else if (g_data.map.mat[x][y] == 'E')
	// {
    //     ft_fillxy(&(w->dir.x), &(w->dir.y), 0, 1);
    // 	ft_fillxy(&(w->plane.x), &(w->plane.y), 0.66, 0.0);
	// }
	// w->time = 0;
	// w->oldtime = 0;
    return (0);
}


void	ft_raydir(t_world *w, int x)
{
	w->camerax = 2 * x / (double)g_data.scr.image.width - 1; //(double)screenWidth)
	w->raydir.x = w->dir.x + w->plane.x * w->camerax;
	w->raydir.y = w->dir.y + w->plane.y * w->camerax;
	//printf("stexraydirna%f\n", w->raydir.y);
}

void		ft_map_box(t_world *w)
{
	w->map.x = (int)(w->pos.x);
	w->map.y = (int)(w->pos.y);
}

void	ft_deltadist(t_world *w)
{
	//if (w->raydir.x == 0)
		//w->deltadist.x = 10000000;
	//else
	w->deltadist.x = fabs(1 / w->raydir.x);
	//if (w->raydir.y == 0)
	//	w->deltadist.y = 10000000;
	//else
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

int		ft_DDA(t_world *w)
{
	//printf("ekav");
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
}

void	ft_perpwalldist(t_world *w)
{
	if (w->side == 0)
		w->perpwalldist = (w->map.x - w->pos.x + (1 - w->step.x) / 2) / w->raydir.x;
	else
	{
		w->perpwalldist = (w->map.y - w->pos.y + (1 - w->step.y) / 2) / w->raydir.y;
		//printf("waldistna%f\n", w->perpwalldist);
	}
	//printf("mapna%d\n posna%f", w->map.x, w->pos.x);
	//printf("mapnay%d\n posnay%f, stepna%d, rayna%f\n", w->map.y, w->pos.y, w->step.y, w->raydir.y);

	
}

void	start_end_pixel(t_world *w)
{
	w->lineheight = (int)(g_data.scr.image.height / w->perpwalldist); //screenheight;
	w->drawstart = -(w->lineheight) / 2 + g_data.scr.image.height / 2; //screenheight;
	if (w->drawstart < 0)
		w->drawstart = 0;
	w->drawend = (w->lineheight) / 2 + g_data.scr.image.height / 2; //screenheight;
	if (w->drawend < 0) //screnehgith
		w->drawend = g_data.scr.image.height - 1;
	g_data.side = '0';
	if (w->side == 0)
	{
		if (w->raydir.x < 0)
		{
			//printf("Ceiling color before: %d\n", g_data.ceiling);
			//printf("Ceiling color after: %d\n",g_data.ceiling);
			//Ooooooof de ashxati asum em
			//g_data.side = 'N';
			g_data.current = g_data.north;
		}	
		else if (w->raydir.x > 0)
		{
			//g_data.side = 'S';
			g_data.current = g_data.south;
		}
	}
	else if (w-> side == 1)
	{
		if (w->raydir.y < 0)
		{
	 		//g_data.side = 'W';
			g_data.current = g_data.west;
		}
	 	else if (w->raydir.y > 0)
		{
	 		//g_data.side = 'E';
			g_data.current = g_data.east;
		}
	}

}

int		ft_texx(t_world *w)
{
	int		texx;
	double	wallx;

	//if (ft_isdigit(g_data.map.mat[w->map.x][w->map.y]))
		//texnum = ft_atoi(g_data.map.mat[w->map.x][w->map.y]) - 1;   ++++
	if (w->side == 0)
		wallx = w->pos.y + w->perpwalldist * w->raydir.y;
	else
		wallx = w->pos.x + w->perpwalldist * w->raydir.x;
	wallx -=  floor((wallx));
	//printf("blnay%f %f %f\n", w->pos.x, w->perpwalldist, w->raydir.x);
	//printf("bl1%f\n", wallx);
	texx  = (int)(wallx * (double)g_data.current.width); //texturewidth
	if (w->side == 0  && w->raydir.x > 0)
	//{
		texx = g_data.current.width - texx - 1; //texturewidth
		//w->c = 'N';
	//}
	if (w->side  == 1 && w->raydir.y < 0)
		texx = g_data.current.width - texx - 1; //texturewith
	return (texx);
}

int     ft_algorithm(t_file *f)
{
    t_world     *w;
	int			y;
	int			x;
	int			texx;

	x = 0;
    w = g_data.w;
	ft_init(w, *f);
	// printf("Dirx: %f, diry: %f\n", w->dir.x, w->dir.y);
	alter_map(w); //of
	//print_mat( g_data.map.mat, g_data.map.height);
	//screen in mlx like screen(screenWidth, screenHeight, 0, "Raycaster");
    //move
	//rotate
	//draw_floor
	while (x < g_data.scr.image.width) //screenWidth)
	{
		y = 0;
		ft_raydir(w, x);
		ft_map_box(w);
		ft_deltadist(w);
		ft_step_sidedist(w);
		ft_DDA(w);
		ft_perpwalldist(w);
		start_end_pixel(w);
		texx = ft_texx(w);
		// while (y < g_data.scr.image.height)
		// {
			//if (y >= w->drawstart && y < w->drawend)
				//texy = 1.0 * (y - w->drawstart) / wall_height * g_data.north.height);
		//	draw(x, w, texx);
		// }
		//colors(w, f);
		// printf("X: %d\n", x);
		//printf("Drawstart: %d\n", w->drawstart);
		//printf("Drawend: %d\n", w->drawend);
		//draw(x, w, texx);
		// printf("%d\n", w->drawstart);
		// printf("%d\n", w->drawend);
		//printf("bl%d\n", texx);
		draw(x, w, texx);
		x++;
	}
	mlx_put_image_to_window(g_data.scr.mlx, g_data.scr.window, g_data.scr.image.ptr, 0, 0);
	//mlx_string_put(g_data.scr.mlx, g_data.scr.window, 25, 25, 0x00FF0000, " ");
	mlx_do_sync(g_data.scr.mlx);
	return (0);
}