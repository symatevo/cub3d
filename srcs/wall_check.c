/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/10 13:25:52 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/23 21:17:32 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	iterate_spaces(int y, int *x)
{
	if (g_data.map.mat[y][*x] == ' ')
	{
		while (*x < g_data.map.width && g_data.map.mat[y][*x] == ' ')
				*x = *x + 1;
		if (*x < g_data.map.width && g_data.map.mat[y][*x] == '0')
			return (0);
	}
	return (1);
}

int	on_edge(int y, int x)
{
	return (y == 0 || x == 0 || x == g_data.map.width - 1
		|| y == g_data.map.height - 1);
}

int	surrounded_by_space(int y, int x, char c)
{
	if ((y - 1) >= 0)
	{
		if (g_data.map.mat[y - 1][x] == ' ')
			return (1);
		if ((x - 1) >= 0 && g_data.map.mat[y - 1][x - 1] == ' ')
			return (1);
		if ((x + 1) < g_data.map.width && g_data.map.mat[y - 1][x + 1] == ' ')
			return (1);
	}
	if ((y + 1) < g_data.map.height)
	{
		if (g_data.map.mat[y + 1][x] == ' ')
			return (1);
		if ((x - 1) >= 0 && g_data.map.mat[y + 1][x - 1] == ' ')
			return (1);
		if ((x + 1) < g_data.map.width && g_data.map.mat[y + 1][x + 1] == ' ')
			return (1);
	}
	if ((x - 1) >= 0)
		if (g_data.map.mat[y][x - 1] == ' ')
			return (1);
	if ((x + 1) < g_data.map.width)
		if (g_data.map.mat[y][x + 1] == ' ')
			return (1);
	return (0);
}

int	check_row(int y)
{
	int	x;

	x = 0;
	while (x < g_data.map.width)
	{
		if (!iterate_spaces(y, &x))
			return (0);
		if (x < g_data.map.width)
			if (g_data.map.mat[y][x] == '0'
				&& (surrounded_by_space(y, x, g_data.map.mat[y][x])
				|| on_edge(y, x)))
				return (0);
		x++;
	}
	return (1);
}

int	check_walls(void)
{
	int	y;

	y = 0;
	while (y < g_data.map.height)
	{
		printf("Y: %d\n", y);
		printf("The line: %s\n", g_data.map.mat[y]);
		if (!check_row(y))
			return (0);
		y++;
	}
	return (1);
}
