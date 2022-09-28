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
		return (ft_error("Wrong arguments in file"));
	}
	free(words);
	return (1);
}

int	ft_parsing_checks(char *line, t_file *f)
{
	if (f->idx != 6 && word_count(line) == 2)
	{
		if (!(line_parse(f, line)))
			return (0);
	}
	else if (f->idx == 6)
	{
		if ((line[0] == ' ' || line[0] == '1') && str_is_map(line))
			return (1);
		if (ft_strcmp(line, "\n") != 0 && !str_is_space(line))
			return (ft_error("Double in file"));
	}
	else if (ft_strcmp(line, "\n") != 0 && !str_is_space(line))
		return (ft_error("Bad character in file"));
	return (-1);
}

int	parsing(int argc, char **argv, t_file *f)
{
	char	*line;
	int		output;

	output = -1;
	if (argc == 2 && check_exec(argv[1]))
	{
		if (!(file_opening(&(f->fd_file), argv[1])))
			return (ft_error("Wrong file"));
		line = get_next_line(f->fd_file);
		while (line > 0)
		{
			if (output == 1)
				return (1);
			else if (output == 0)
				return (0);
			output = ft_parsing_checks(line, f);
			line = get_next_line(f->fd_file);
		}
	}
	return (ft_error("Wrong argument"));
}
