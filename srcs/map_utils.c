/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/08 18:08:18 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/10 13:43:22 by aapresya         ###   ########.fr       */
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

int	valid_char(char c)
{
	return (c == '0' || c == '1' || c == ' ');
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
			if (!valid_char(g_data.map.mat[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
