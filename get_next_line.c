/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:21:41 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/24 22:29:05 by kfu           ########   odam.nl         */
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

static int	cleanline(char **arr, char **line, int fd, int i)
{
	int		len;
	char	*tmp;

	len = 0;
	if (i < 0)
		return (-1);
	else if (i == 0 && arr[fd] == NULL)
		return (0);
	while (arr[fd][len] != '\n' && arr[fd][len] != '\0')
		len++;
	if (arr[fd][len] == '\n')
	{
		*line = ft_substr(arr[fd], 0, len);
		tmp = ft_strdup(arr[fd] + len + 1);
		ft_strdel(&arr[fd]);
		arr[fd] = tmp;
		if (arr[fd][0] == '\0')
			ft_strdel(&arr[fd]);
	}
	else
	{
		*line = ft_strdup(arr[fd]);
		ft_strdel(&arr[fd]);
	}
	return (1);
}

int			get_next_line(int fd, char **line)
{
	int			i;
	char		buff[BUFF_SIZE + 1];
	char		*tmp;
	static char *arr[5000];

	if (fd < 0 || line == NULL)
		return (-1);
	if (read(fd, buff, BUFF_SIZE) == 0)
		return (0);
	while (i > 0)
	{
		buff[i] = '\0';
		if (arr[fd] == NULL)
			arr[fd] = ft_strdup(buff);
		else
		{
			tmp = ft_strjoin(arr[fd], buff);
			ft_strdel(&arr[fd]);
			arr[fd] = tmp;
		}
		if (ft_strchr(buff, '\n'))
			break ;
		i = read(fd, buff, BUFF_SIZE);
	}
	return (cleanline(arr, line, fd, i));
}
