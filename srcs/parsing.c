#include "../Includes/cub3d.h"

int check_exec(char *str)
{
    int     index;
    char    *ptr;
    char    *new;

    ptr = str;
    printf("%d\n", index);
    printf("%s\n", ft_reverse(ptr));
    new = ft_substr(ptr, 0, 4);
    if (ft_strcmp(new, "buc.") == 0)
        return 1;
    return 0;
    printf("%s\n", new);
}

int parsing(int argc, char **argv)
{
    char    **line;
    int     fd;

    if (argc == 2 && check_exec(argv[1]))
    {
        printf("ok");
        while(1)
        {
            break;
        }
    }
    printf("ok");
    return(1);
}