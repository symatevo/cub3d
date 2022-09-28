/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: symatevo <symatevo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 16:53:54 by symatevo          #+#    #+#             */
/*   Updated: 2022/09/28 15:54:20 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	check_exec(char *str)
{
	int		idx;

	idx = ft_strlen(str);
	if (str[idx - 1] == 'b' && str[idx - 2] == 'u'
		&& str[idx - 3] == 'c' && str[idx - 4] == '.')
		return (1);
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

int	str_is_map(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '1' && str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}
