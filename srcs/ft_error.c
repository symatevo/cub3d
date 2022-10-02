/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 17:09:28 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/28 15:55:59 by symatevo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

int	ft_error(char *err)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd(err, 2);
	ft_putchar_fd('\n', 2);
	return (0);
}

int	file_opening(int *fd, char *str)
{
	*fd = open(str, O_RDONLY);
	if (*fd < 1)
		return (0);
	return (1);
}

int	file_openingt(t_file *f, char *str, int i)
{
	if (f->texture[i].file)
		return (0);
	f->fd = open(str, O_RDONLY);
	if (f->fd < 1)
		return (0);
	return (1);
}

int	free_return(int ret, t_file *f)
{
	int	i;

	i = 0;
	while (i < 4)
		free(f->texture[i++].file);
	i = 0;
	free(f);
	free(g_data.w);
	while (i < g_data.map.height && g_data.map.height < 2)
		free(g_data.map.mat[i++]);
	free(g_data.map.mat);
	return (ret);
}

void	free_words(char	**words, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(words[i]);
		i++;
	}
	free(words);
}
