#include "../Includes/cub3d.h"

t_data g_data;

int     main(int argc, char **argv)
{
    t_world     world;
    t_mlx       mlx;

    //window_create(&mlx);
    //parsing(argc, argv);
    //main_algorithm(&world);
    //memory_clear();
    read_map("small_map.cub");
    //print_mat(g_data.map.mat, g_data.map.height);
}
