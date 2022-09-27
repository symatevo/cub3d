/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:54 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/27 21:27:59 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	texture_fill(t_texture *t, char *str, char *file, int *idx)
{
	t->file = file;
	t->id[0] = str[0];
	t->id[1] = str[1];
	t->id[2] = '\0';
	*idx = *idx + 1;
}

void	cf_fill(t_ceil_floor *cf, char *str, char *w_sec, int *idx)
{
	char	**rgb;

	rgb = ft_split(w_sec, ',');
	cf->rgb.r = ft_atoi(rgb[0]);
	cf->rgb.g = ft_atoi(rgb[1]);
	cf->rgb.b = ft_atoi(rgb[2]);
	cf->id[0] = str[0];
	cf->id[1] = '\0';
	free(rgb);
	*idx = *idx + 1;
}

int	line_parse(t_file *f, char *str)
{
	char	**words;

	words = ft_words(str);
	if (ft_strcmp(words[0], "NO") == 0 && file_opening(&(f->fd), words[1]))
		texture_fill(&(f->texture[0]), "NO", words[1], &(f->idx));
	else if (ft_strcmp(words[0], "SO") == 0 && file_opening(&(f->fd), words[1]))
		texture_fill(&(f->texture[1]), "SO", words[1], &(f->idx));
	else if (ft_strcmp(words[0], "WE") == 0 && file_opening(&(f->fd), words[1]))
		texture_fill(&(f->texture[2]), "WE", words[1], &(f->idx));
	else if (ft_strcmp(words[0], "EA") == 0 && file_opening(&(f->fd), words[1]))
		texture_fill(&(f->texture[3]), "EA", words[1], &(f->idx));
	else if (ft_strcmp(words[0], "F") == 0 && check_rgb(words[1]))
		cf_fill(&(f->cf[0]), "F", words[1], &(f->idx));
	else if (ft_strcmp(words[0], "C") == 0 && check_rgb(words[1]))
		cf_fill(&(f->cf[1]), "C", words[1], &(f->idx));
	else
	{
		free(words);
		ft_error("Wrong arguments in file");
	}
	free(words);
	return (1);
}

int	file_opening(int *fd, char *str)
{
	*fd = open(str, O_RDONLY);
	if (*fd < 1)
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_file *f)
{
	char	*line;
	int		output;

	output = 0;
	if (argc == 2 && check_exec(argv[1], f))
	{
		if (!(file_opening(&(f->fd_file), argv[1])))
			return (ft_error("Wrong file"));
		line = get_next_line(f->fd_file);
		while (line > 0)
		{
			output = ft_parsing_checks(f->idx, line, f, f->fd_file);
			line = get_next_line(f->fd_file);
		}
		if (output == 1)
			return (1);
		else
			return (0);
	}
	return (ft_error("Wrong argument"));
}
