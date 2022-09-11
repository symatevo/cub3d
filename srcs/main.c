#include "../Includes/cub3d.h"

int bl(t_file f)
{
    printf("blll\n");
    printf("%s %d %s %d\n" , f.texture[0].id, f.texture[0].file_name, f.texture[1].id, f.texture[1].file_name);
    printf("%s %d %s %d\n" , f.texture[2].id, f.texture[2].file_name, f.texture[3].id, f.texture[3].file_name);
    printf("%s %d %d %d %s %d %d %d\n", f.cf[0].id, f.cf[0].rgb.r, f.cf[0].rgb.g, f.cf[0].rgb.b, f.cf[1].id, f.cf[1].rgb.r, f.cf[1].rgb.g, f.cf[1].rgb.b);
    printf("blll\n");
    return(1);
}

int     main(int argc, char **argv)
{
    t_file      *f;
    //t_world     world;
    //t_mlx       mlx;

    f = malloc(sizeof(t_file));
    parsing(argc, argv, f);
    bl(*f);
    //main_algorithm(&world);
    //memory_clear();
    return (0);
}
