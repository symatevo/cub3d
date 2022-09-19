#include "../Includes/cub3d.h"

int     check_exec(char *str, t_file *f)
{
    char    ptr[ft_strlen(str)];
    char    *new;

    ft_strlcpy(ptr, str, ft_strlen(str) + 1);
    ptr[ft_strlen(str)] = '\0';
    new = ft_substr(ft_reverse(ptr), 0, 4);
    if (ft_strcmp(new, "buc.") == 0)
        return 1;
    free(new);
    free(f);
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

void    texture_fill(t_texture *t, char *str, int fd, int *idx)
{
    t->file_name = fd;
	t->id[0] = str[0];
	t->id[1] = str[1];
	t->id[2] = '\0';
	*idx = *idx + 1;
}

void    cf_fill(t_ceil_floor *cf, char *str, char *w_sec, int *idx)
{
    char **rgb;

    rgb = ft_split(w_sec, ',');
    cf->rgb.r = ft_atoi(rgb[0]);
    cf->rgb.g = ft_atoi(rgb[1]);
    cf->rgb.b = ft_atoi(rgb[2]);
    cf->id[0] = str[0];
	cf->id[1] = '\0';
    free(rgb);
	*idx = *idx + 1;
}

int     line_parse(t_file *f, char *str)
{
    char    **words;

    words = ft_words(str);
    if (ft_strcmp(words[0], "NO") == 0 && file_opening(&(f->fd), words[1]))
        texture_fill(&(f->texture[0]), "NO", f->fd, &(f->idx));
    if (ft_strcmp(words[0], "NO") == 0 && file_opening(&(f->fd), words[1]))
        texture_fill(&(f->texture[0]), "NO", f->fd, &(f->idx));
    else if (ft_strcmp(words[0], "SO") == 0 && file_opening(&(f->fd), words[1]))
        texture_fill(&(f->texture[1]), "SO", f->fd, &(f->idx));
    else if (ft_strcmp(words[0], "WE") == 0 && file_opening(&(f->fd), words[1]))
        texture_fill(&(f->texture[2]), "WE", f->fd, &(f->idx));
    else if (ft_strcmp(words[0], "EA") == 0 && file_opening(&(f->fd), words[1]))
        texture_fill(&(f->texture[3]), "EA", f->fd, &(f->idx));
    else if (ft_strcmp(words[0], "F") == 0 && check_rgb(words[1]))
        cf_fill(&(f->cf[0]), "F", words[1], &(f->idx));
    else if (ft_strcmp(words[0], "C") == 0 && check_rgb(words[1]))
        cf_fill(&(f->cf[1]), "C", words[1], &(f->idx));
    else
    {
        free(words);
        print_error ("Wrong arguments in file");
    }
    free(words);
    return (1);
}

int file_opening(int *fd, char *str)
{
    *fd = open(str, O_RDONLY);
    if (*fd < 1)
        return (0);
    return (1);
}

int parsing(int argc, char **argv, t_file *f)
{
    char    *line;
    int     fd;

    f->idx = 0;
    if (argc == 2 && check_exec(argv[1], f))
    {
        if (!(file_opening(&(f->fd), argv[1])))
            return (ft_error("Wrong file \n"));
        fd = f->fd;
        while ((line = get_next_line(fd)) > 0)
		{
            if (f->idx != 6 && word_count(line) == 2)
            {
                if (!(line_parse(f, line)))
                    return (0);
            }
			else if (f->idx == 6)
			{
				if (line[0] == ' ' || line[0] == '0' || line[0] == '1')
					return (1);
			}
            else if (ft_strcmp(line, "\n") != 0 && !str_is_space(line))
                return (ft_error("Bad character in file"));
		}
    }
    return (ft_error("Wrong number of arguments"));
}