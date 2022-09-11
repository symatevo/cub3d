#include "../Includes/cub3d.h"

int     check_exec(char *str)
{
    char    ptr[ft_strlen(str)];
    char    *new;

    ft_strlcpy(ptr, str, ft_strlen(str) + 1);
    ptr[ft_strlen(str)] = '\0';
    new = ft_substr(ft_reverse(ptr), 0, 4);
    if (ft_strcmp(new, "buc.") == 0)
        return 1;
    free(new);
    print_error("Wrong file type \n");
    return 0;
}

int     check_range(char *str)
{
    int num;

    num = -1;
    num = ft_atoi(str);
    if (num >= 0 && num <= 255)
        return (1);
    return (0);
}

int     check_rgb(char *str)
{
    char **words;
    int i;
    int w;

    w = 0;
    i = 0;
    words = ft_split(str, ',');
    while (words[i] != NULL)
        i++;
    if (i != 3)
        return 0;
    i = 0;
    while (i < 3)
    {
        if (check_isnum(words[i]))
            if (check_range(words[i]))
                w++;
        i++;
        }
    free(words);
    if (w == 3)
        return 1;
    return 0;
}

void    texture_fill(t_texture *t, char *str, int fd)
{
    t->file_name = fd;
    ft_strlcpy(t->id, str, ft_strlen(str) + 1);
    t->id[ft_strlen(str)] = '\0';
}

void    cf_fill(t_ceil_floor *cf, char *str, char *w_sec)
{
    char **rgb;

    rgb = ft_split(w_sec, ',');
    (&cf->rgb)->r = ft_atoi(rgb[0]);
    (&cf->rgb)->g = ft_atoi(rgb[1]);
    (&cf->rgb)->b = ft_atoi(rgb[2]);

    ft_strlcpy(cf->id, str, ft_strlen(str) + 1);
    cf->id[ft_strlen(str)] = '\0';
    free(rgb);
}

void     line_parse(t_file *f, char *str)
{
    char    **words;
    int     fd;

    words = ft_words(str);
    if (ft_strcmp(words[0], "NO") == 0 && (fd = open(words[1], O_RDONLY)) != -1)
        texture_fill(&f->texture[0], "NO", fd);
    else if (ft_strcmp(words[0], "SO") == 0 && (fd = open(words[1], O_RDONLY)) != -1)
        texture_fill(&f->texture[1], "SO", fd);
    else if (ft_strcmp(words[0], "WE") == 0 && (fd = open(words[1], O_RDONLY)) != -1)
        texture_fill(&f->texture[2], "WE", fd);
    else if (ft_strcmp(words[0], "EA") == 0 && (fd = open(words[1], O_RDONLY)) != -1)
        texture_fill(&f->texture[3], "EA", fd);
    else if (ft_strcmp(words[0], "F") == 0 && check_rgb(words[1]))
        cf_fill(&f->cf[0], "F", words[1]);
    else if (ft_strcmp(words[0], "C") == 0 && check_rgb(words[1]))
        cf_fill(&f->cf[1], "C", words[1]);
    else
    {
        //printf("%d", check_rgb(words[1]));
        //printf("%s", str);
        free(words);
        print_error ("Wrong arguments");
    }
    free(words);
}

int parsing(int argc, char **argv, t_file *f)
{
    char    *line;
    int     fd;

    if (argc == 2 && check_exec(argv[1]))
    {
        if ((fd = open(argv[1], O_RDONLY)) < 1)
            print_error("Wrong file \n");
        while ((line = get_next_line(fd)) > 0)
            if (word_count(line) == 2)
            {
                line_parse(f, line);
            }
            else if (ft_strcmp(line, "\n") != 0)
            {
                //printf("%s", line);
                //if (!map_check())
                //if (line[0] != '1')
                   // print_error("Wrong arguments");
            }
    }
    else
        print_error("Wrong number of arguments");
    return(0);
}