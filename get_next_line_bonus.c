/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmarzouk <rmarzouk@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 15:26:38 by rmarzouk          #+#    #+#             */
/*   Updated: 2024/02/10 19:12:03 by rmarzouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	ft_read(char **remain, int fd)
{
	char	*buffer;
	int		r;

	r = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
	{
		ft_clean(remain);
		return ;
	}
	while (find_nl(*remain) < 0 && r != 0)
	{
		r = read(fd, buffer, BUFFER_SIZE);
		if (r == -1)
		{
			free(buffer);
			ft_clean(remain);
			return ;
		}
		buffer[r] = '\0';
		ft_strjoin(remain, buffer);
	}
	free(buffer);
}

void	ft_line(char **remain, char **line)
{
	int	i;

	if (!(*remain) || !(*remain)[0])
		return ;
	i = find_nl(*remain) + 1;
	if (i == 0)
		i = ft_strlen(*remain);
	*line = malloc((i + 1) * sizeof(char));
	if (!*line)
	{
		ft_clean(remain);
		return ;
	}
	(*line)[i] = '\0';
	while (i--)
		(*line)[i] = (*remain)[i];
}

void	ft_next_line(char **remain)
{
	char	*rest;
	int		i;
	int		j;

	if (!(*remain))
		return ;
	j = 0;
	i = find_nl(*remain) + 1;
	if (i == 0)
	{
		ft_clean(remain);
		return ;
	}
	rest = malloc(ft_strlen(*remain + i) + 1);
	if (!rest)
	{
		ft_clean(remain);
		return ;
	}
	while ((*remain)[i])
		rest[j++] = (*remain)[i++];
	rest[j] = '\0';
	free(*remain);
	*remain = rest;
}

char	*get_next_line(int fd)
{
	static char	*remain[OPEN_MAX];
	char		*line;

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ft_read(remain + fd, fd);
	ft_line(remain + fd, &line);
	ft_next_line(remain + fd);
	return (line);
}
