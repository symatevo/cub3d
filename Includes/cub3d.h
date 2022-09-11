#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <mlx.h>
#include "libft/libft.h"

typedef struct s_texture{
    char    id[2];
    int     file_name;
}   t_texture;

typedef struct s_rgb{
    int r;
    int g;
    int b;
}   t_rgb;

typedef struct s_ceil_floor{
    char    id[1];
    t_rgb   rgb;
}   t_ceil_floor;

typedef struct s_file {
    t_texture       texture[4];
    t_ceil_floor    cf[2];
    int             **map;
    int             idx;
}   t_file;

typedef struct s_xy{
    double x;
    double y;
} t_xy;

typedef struct s_world{
    t_xy    pos;
    t_xy    raydir;
    t_xy    sidedist;
    t_xy    deltadist;
    t_xy    step;
    int     side;
    int     hit;
    double  perpwalldist;
} t_world;

typedef struct s_mlx{
    void    *mlx;
    void    *mlx_win;
}   t_mlx;

int     parsing(int argc, char **argv, t_file *f);
char    *get_next_line(int fd);
