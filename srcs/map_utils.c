/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:08:18 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/26 17:00:00 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

void	print_mat(char **mat, int len)
{
	int	i;

	i = 0;
	ft_putchar_fd('\n', 1);
	while (i < len)
	{
		ft_putstr_fd(mat[i], 1);
		ft_putchar_fd('\n', 1);
		i++;
	}
}

int	valid_char(char c, int x, int y)
{
	if (c == '0' || c == '1' || c == ' ')
		return (1);
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
	{
		if (on_edge(y, x))
			return (0);
		if (g_data.spawn != ' ')
			return (0);
		g_data.player_x = x;
		g_data.player_y = y;
		g_data.spawn = c;
		return (1);
	}
	return (0);
}

int	check_chars(void)
{
	int	x;
	int	y;

	y = 0;
	while (y < g_data.map.height)
	{
		x = 0;
		while (x < g_data.map.width)
		{
			if (!valid_char(g_data.map.mat[y][x], x, y))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
