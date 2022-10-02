/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 14:20:46 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/27 20:20:00 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <sys/types.h>
# include <sys/stat.h>
# include <sys/time.h>
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
	char	id[3];
	int		file_name;
	char	*file;
}	t_texture;

typedef struct s_rgb{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_ceil_floor{
	char	id[2];
	t_rgb	rgb;
}	t_ceil_floor;

typedef struct s_map
{
	int		width;
	int		height;
	char	**mat;
}	t_map;

typedef struct s_file {
	t_texture		texture[4];
	t_ceil_floor	cf[2];
	int				idx;
	int				fd_file;
	int				fd;
}	t_file;

typedef struct s_xy{
	double	x;
	double	y;
}	t_dxy;

typedef struct m_xy{
	int	x;
	int	y;
}	t_ixy;

typedef struct s_img
{
	void			*ptr;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
	int				width;
	int				height;
}					t_img;

typedef struct s_world{
	t_dxy	pos;
	t_dxy	dir;
	t_dxy	raydir;
	t_dxy	plane;
	t_dxy	sidedist;
	t_dxy	deltadist;
	t_ixy	step;
	t_ixy	map;
	int		x;
	int		y;
	double	camerax;
	int		side;
	char	c;
	int		hit;
	int		lineheight;
	int		drawstart;
	int		drawend;
	double	perpwalldist;
}	t_world;

typedef struct s_keys
{
	char		up;
	char		down;
	char		left;
	char		right;
	char		rotright;
	char		rotleft;
	char		check;
}				t_keys;

typedef struct s_screen
{
	void		*mlx;
	void		*window;
	t_img		image;
}				t_screen;

typedef struct s_data
{
	t_screen	scr;
	t_map		map;
	double		player_x;
	double		player_y;
	char		spawn;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_keys		keys;
	char		side;
	int			ceiling;
	int			floor;
	t_world		*w;
	t_img		current;
	int			i;
	int			u;
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
int				surrounded_by_space(int y, int x);
int				check_row(int y);
int				check_walls(void);
int				check_chars(void);
int				valid_char(char c, int x, int y);
void			fill_map(int i, int *j, char *line);
int				file_opening(int *fd, char *str);
int				file_openingt(t_file *f, char *str, int i);
int				ft_algorithm(void);
int				parsing(int argc, char **argv, t_file *f);
char			*get_next_line(int fd);
void			init_data(void);
int				ft_mlx_pressed(int keycode, t_keys *keys);
int				ft_mlx_released(int keycode, t_keys *keys);
int				ft_mlx_terminate(int keycode, t_keys *keys);
int				ft_get_sprites(t_file *f);
void			ft_calculate_resolution(void);
int				create_trgb(int t, int r, int g, int b);
int				valid_indices(int x, int y);
void			alter_map(t_world *w);
void			draw(int x, t_world *w, int texx);
void			ft_mlx_pixel_put(t_img *image, int x, int y, int color);
unsigned int	ft_mlx_pixel_get(t_img *image, int x, int y);
void			ft_find_pos(double *posx, double *posy);
void			ft_fillxy(double *x, double *y, double xv, double yv);
void			ft_raydir(t_world *w, int x);
void			ft_map_box(t_world *w);
void			ft_deltadist(t_world *w);
void			ft_step_sidedist(t_world *w);
void			ft_init(t_world *w);
int				spaces(char *line);
void			init_mlx(void);
int				check_exec(char *str);
int				check_range(char *str);
int				check_comma(char *str);
int				check_rgb(char *str);
int				file_opening(int *fd, char *str);
int				str_is_map(char *str);
int				line_parse(t_file *f, char *str);
int				ft_parsing_checks(char *line, t_file *f);
int				free_return(int ret, t_file *f);
void			free_words(char	**words, int i);
int				check_end(char *line, int fd, int i, int *j);
#endif
