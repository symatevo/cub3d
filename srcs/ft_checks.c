/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:54 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/27 21:59:05 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	check_exec(char *str, t_file *f)
{
	char	*ptr;
	char	*new;

	ft_strlcpy(ptr, str, ft_strlen(str) + 1);
	ptr[ft_strlen(str)] = '\0';
	new = ft_substr(ft_reverse(ptr), 0, 4);
	if (ft_strcmp(new, "buc.") == 0)
	{
		free(new);
		return (1);
	}
	free(new);
	return (0);
}

int	check_range(char *str)
{
	int	num;

	num = -1;
	num = ft_atoi(str);
	if (num >= 0 && num <= 255)
		return (1);
	return (0);
}

int	check_comma(char *str)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ',')
			num++;
		i++;
	}
	if (num == 2)
		return (1);
	return (0);
}

int	check_rgb(char *str)
{
	char	**words;

	g_data.u = 0;
	g_data.i = 0;
	words = ft_split(str, ',');
	while (words[g_data.i] != NULL)
		g_data.i++;
	if (g_data.i == 3 && check_comma(str))
	{
		g_data.i = 0;
		while (g_data.i < 3)
		{
			if (check_isnum(words[g_data.i]))
				if (check_range(words[g_data.i]))
					g_data.u++;
			g_data.i++;
		}
	}	
	free(words);
	if (g_data.u == 3)
		return (1);
	return (0);
}

int	ft_parsing_checks(int idx, char *line, t_file *f, int fd)
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
		if (ft_strcmp(line, "\n") != 0 && !str_is_space(line))
			return (ft_error("Double in file"));
	}
	else if (ft_strcmp(line, "\n") != 0 && !str_is_space(line))
		return (ft_error("Bad character in file"));
	return (0);
}
