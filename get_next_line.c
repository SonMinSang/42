/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mson <mson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/02 21:18:59 by mson              #+#    #+#             */
/*   Updated: 2021/07/28 04:52:50 by mson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
int	loc_newline(char *buf)
{
	int		loc;

	loc = 0;
	while (buf[loc])
	{
		if (buf[loc] == '\n')
			return (loc);
		loc++;
	}
	return (-1);
}

char	*line_process(char **save, int offset)
{
	char	*temp;
	int		size;
	char	*line;
	
	size = (int)ft_strlen(*save);
	line = ft_substr(*save, 0, offset + 1);
	if (size == offset + 1)
	{
		printf("%p\n", line);
		free(*save);
		*save = 0;
		return(line);
	}
	temp = ft_strdup(*save + offset + 1);
	free(*save);
	*save = temp;
	return (line);
}

char	*end_read(int read_size, char **save)
{
	int		offset;
	char	*line;

	offset = 0;
	if (read_size == -1)
		return (NULL);
	if (*save)
	{
		offset = loc_newline(*save);
		if (offset >= 0)
			return (line_process(save, offset));
		else
		{
			line = *save;
			*save = 0;
			return (line);
		}
	}
	else
		return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*save[OPEN_MAX];
	char		buf[BUFFER_SIZE + 1];
	int			read_size;
	int			offset;
	char		*temp;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (0);
	while ((read_size = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[read_size] = '\0';
		temp = ft_strjoin(save[fd], buf);
		free(save[fd]);
		save[fd] = temp;
		offset = loc_newline(save[fd]);
		if (offset >= 0)
			return (line_process(&save[fd], offset));
	}
	return (end_read(read_size, &save[fd]));
}

int main(void)
{
	int fd = open("b",O_RDONLY);

	printf("%s", get_next_line(fd));
	printf("%s", get_next_line(fd));
	while (1)
	{
	};
}
