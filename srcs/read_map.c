/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 19:13:33 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/26 17:47:25 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	get_height_width(int fd)
{
	char	*line;
	int		r;

	while (1)
	{
		r = get_nextline(fd, &line);
		if (r && (int)ft_strlen(line) > g_data.map.width)
		{	
			g_data.map.width = ft_strlen(line);
		}
		g_data.map.height++;
		free(line);
		if (!r)
			break ;
	}
}

int	find_map(char *filename)
{
	char	*line;
	int		fd;
	int		r;
	int		i;

	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (1)
	{
		r = get_nextline(fd, &line);
		if (line && (spaces(line) || line[0] == '1' || line[0] == '0'))
		{
			g_data.map.height = 1;
			g_data.map.width = ft_strlen(line);
			free(line);
			get_height_width(fd);
			return (i);
		}
		free(line);
		if (!r)
			break ;
		i++;
	}
	close(fd);
	return (-1);
}

void	fill_map(int i, int *j, char *line)
{
	while (*j < (int)ft_strlen(line))
	{
		g_data.map.mat[i][*j] = line[*j];
		*j = *j + 1;
	}
	if ((int)ft_strlen(line) < g_data.map.width)
	{
		while (*j < g_data.map.width)
		{
			g_data.map.mat[i][*j] = ' ';
			*j = *j + 1;
		}
	}	
}

int	into_mat(char *filename, int line_num)
{
	char	*line;
	int		fd;
	int		r;
	int		i;
	int		j;

	fd = open(filename, O_RDONLY, 0);
	i = 0;
	while (i++ < line_num)
	{
		get_nextline(fd, &line);
		free(line);
	}
	i = 0;
	while (1)
	{
		r = get_nextline(fd, &line);
		if (!(check_end(line, fd, i, &j)))
			return (0);
		if (!r)
			break ;
		i++;
	}
	close(fd);
	return (1);
}

int	read_map(char *filename)
{
	int	i;
	int	mat_line;

	i = 0;
	g_data.map.height = 0;
	g_data.map.width = 0;
	mat_line = find_map(filename);
	if (g_data.map.height <= 2 || g_data.map.width <= 2)
		return (ft_error("The map has wrong dimensions"));
	g_data.map.mat = ft_calloc((g_data.map.height + 1), sizeof(char *));
	while (i < g_data.map.height)
		g_data.map.mat[i++] = ft_calloc((g_data.map.width + 1), sizeof(char));
	if (!into_mat(filename, mat_line))
		return (ft_error("Map is not in the end of the file"));
	if (!check_walls())
		return (ft_error("The map is not surrounded by walls"));
	if (!check_chars())
		return (ft_error("Wrong characters in the map"));
	if (g_data.spawn == ' ')
		return (ft_error("No starting position given"));
	return (1);
}
