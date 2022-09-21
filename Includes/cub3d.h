/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:20:46 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/21 19:02:12 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "libft/libft.h"
# define BUFFER_SIZE 1

typedef struct s_texture{
    char    id[3];
    int     file_name;
	char	*file;
}   t_texture;

typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ceil_floor{
    char    id[2];
    t_rgb   rgb;
}   t_ceil_floor;

typedef struct s_map
{
	int		width;
	int		height;
	char	**mat;
}	t_map;

typedef struct s_file {
	t_texture		texture[4];
	t_ceil_floor	cf[2];
    int             idx;
	int				fd;
}	t_file;

typedef struct s_xy{
	double	x;
	double	y;
}	d_xy;

typedef struct m_xy{
	int	x;
	int	y;
}	i_xy;

typedef struct s_world{
	d_xy	pos;
	d_xy	dir;
	d_xy	raydir;
	d_xy	plane;
	d_xy	sidedist;
	d_xy	deltadist;
	i_xy	step;
	i_xy	map;
	double	time;
	double	oldtime;
	double	camerax;
	int		side;
	int		hit;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	perpwalldist;
}	t_world;

typedef	struct	s_img
{
	void			*ptr;			//pointer to the image
	char			*addr;			//The address of the image
	int				bpp;			//
	int				line_len;		//
	int				endian;			//
	int				width;			//The width of the image
	int				height;			//The height of the image
}					t_img;

typedef struct	s_keys
{
	char		up;
	char		down;
	char		left;
	char		right;
	char		check;
}				t_keys;

typedef struct	s_screen
{
	void		*mlx;
	void		*window;
	t_img		image;
}				t_screen;

typedef struct s_data
{
	t_screen	scr;
	t_map		map;
	int			player_x;
	int			player_y;
	char		spawn;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_keys		keys;
	int			ceiling;
	int			floor;
	int			temp_color;
}	t_data;

extern t_data	g_data;

char			*the_line(char *tmp);
char			*leftover(char *tmp);
char			*ft_strjoin_gln(char *s1, char *s2);
size_t			ft_strlen_gln(char *str);
int				get_nextline(int fd, char **line);
int				read_map(char *filename);
int				find_map(char *filename);
void			get_height_width(int fd);
int				ft_error(char *err);
void			print_mat(char **mat, int len);
int				iterate_spaces(int y, int *x);
int				on_edge(int y, int x);
int				surrounded_by_space(int y, int x, char c);
int				check_row(int y);
int				check_walls(void);
int				check_chars(void);
int				valid_char(char c, int x, int y);
void			fill_map(int i, int *j, char *line);
int				file_opening(int *fd, char *str);
int     		ft_algorithm(t_file *f);
int				parsing(int argc, char **argv, t_file *f);
char			*get_next_line(int fd);
void			init_data();
int				ft_mlx_pressed(int keycode, t_keys *keys);
int				ft_mlx_released(int keycode, t_keys *keys);
int				ft_mlx_terminate(int keycode, t_keys *keys);
int				ft_get_sprites(t_file *f);
void			ft_calculate_resolution(void);
int				create_trgb(int t, int r, int g, int b);
int				valid_indices(int x, int y);
void			alter_map(t_world *w);
void			draw(int x, t_world *w, int texx);
void			mlx_get_screen_size(void *mlx, int *screen_w, int *screen_h);		//idk should I leave it this way?
void			ft_mlx_pixel_put(t_img *image, int x, int y, int color);
unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y);

#endif
