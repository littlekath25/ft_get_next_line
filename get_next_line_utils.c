/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: kfu <kfu@student.codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2020/11/15 12:21:49 by kfu           #+#    #+#                 */
/*   Updated: 2020/11/23 18:27:42 by kfu           ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*tmp;
	size_t				i;
	unsigned int		slen;

	if (!s)
		return (NULL);
	slen = ft_strlen(s);
	tmp = (char *)malloc(len + 1);
	i = 0;
	if (!tmp)
		return (NULL);
	while (i < len && start + i <= slen)
	{
		tmp[i] = s[start + i];
		i++;
	}
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_strchr(const char *str, int c)
{
	while (*str)
	{
		if (*str == (char)c)
			return ((char *)str);
		str++;
	}
	if ((char)c == '\0')
		return ((char *)str);
	return (NULL);
}

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char const *str1, char const *str2)
{
	char	*tmp;
	int		i;
	int		j;

	if (!str1 || !str2)
		return (NULL);
	tmp = (char *)malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	i = 0;
	if (!tmp)
		return (NULL);
	while (str1[i])
	{
		tmp[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		tmp[i + j] = str2[j];
		j++;
	}
	tmp[i + j] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *str)
{
	int		len;
	char	*dup;

	len = 0;
	while (str[len])
	{
		len++;
	}
	dup = (char *)malloc(sizeof(char) * len + 1);
	if (dup == NULL)
		return (NULL);
	len = 0;
	while (str[len])
	{
		dup[len] = str[len];
		len++;
	}
	dup[len] = '\0';
	return (dup);
}
