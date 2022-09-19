/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_An.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapresya <aapresya@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 17:37:32 by aapresya          #+#    #+#             */
/*   Updated: 2022/09/11 18:29:25 by aapresya         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/cub3d.h"

char	*the_line(char *tmp)
{
	int		i;
	int		j;
	char	*line;

	j = 0;
	i = 0;
	while (tmp && tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	line = (char *)malloc(i + 1);
	if (!line)
		return (NULL);
	while (j < i)
	{
		line[j] = tmp[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}

char	*leftover(char *tmp)
{
	int		i;
	int		j;
	char	*ptr;

	j = 0;
	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp && tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	if (tmp[i] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	ptr = (char *)malloc(ft_strlen_gln(tmp) - i + 1);
	if (!ptr)
		return (NULL);
	i++;
	while (tmp[i])
		ptr[j++] = tmp[i++];
	ptr[j] = '\0';
	free(tmp);
	return (ptr);
}

int	get_nextline(int fd, char **line)
{
	int			r;
	char		*buf;
	static char	*tmp;

	buf = (char *)malloc(BUFFER_SIZE + 1);
	if (fd < 0 || !line || BUFFER_SIZE <= 0 || !buf)
		return (-1);
	r = read(fd, buf, BUFFER_SIZE);
	while (r > 0)
	{
		buf[r] = '\0';
		tmp = ft_strjoin_gln(tmp, buf);
		if (ft_strchr(buf, '\n'))
			break ;
		r = read(fd, buf, BUFFER_SIZE);
	}
	free(buf);
	*line = the_line(tmp);
	tmp = leftover(tmp);
	if (r < 0)
		return (-1);
	if (r == 0 && !tmp)
		return (0);
	return (1);
}

char	*ft_strjoin_gln(char *s1, char *s2)
{
	char	*join;
	int		i;
	int		j;

	join = malloc(sizeof(char) * ft_strlen_gln(s1) + ft_strlen_gln(s2) + 1);
	if (!join)
		return (NULL);
	i = 0;
	j = 0;
	if (s1)
		while (s1[i] != '\0')
			join[j++] = s1[i++];
	i = 0;
	if (s2)
		while (s2[i] != '\0')
			join[j++] = s2[i++];
	join[j] = '\0';
	free(s1);
	return (join);
}

size_t	ft_strlen_gln(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
