/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_bonus.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:21:41 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/26 11:09:07 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void		ft_strdel(char **s)
{
	if (s)
	{
		free(*s);
		*s = NULL;
	}
}

static int	cleanline(char **arr, int fd, char **line, int bytes)
{
	int		len;
	char	*tmp;

	len = 0;
	if (bytes == 0 && arr[fd][len] == '\0')
	{
		ft_strdel(arr);
		return (0);
	}
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (arr[fd][len] == '\n')
	{
		*line = ft_substr(arr[fd], 0, len);
		tmp = ft_strdup(arr[fd] + len + 1);
		free(arr[fd]);
		arr[fd] = tmp;
	}
	else
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(arr);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			bytes;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char *arr[MAX_FD];

	if (fd < 0 || fd > MAX_FD || line == NULL)
		return (-1);
	bytes = 1;
	while (bytes)
	{
		bytes = read(fd, buff, BUFF_SIZE);
		buff[bytes] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(arr[fd], buff);
			free(arr[fd]);
			arr[fd] = tmp;
		}
		if (ft_strchr(arr[fd], '\n') || bytes < BUFF_SIZE)
			break ;
	}
	return (cleanline(arr, fd, line, bytes));
}
