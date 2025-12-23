/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnassir <abnassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 06:42:07 by abnassir          #+#    #+#             */
/*   Updated: 2025/12/23 17:26:47 by abnassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *str, int c)
{
	while ((char)c != *str)
	{
		if (!*str)
			return (NULL);
		str++;
	}
	return ((char *)str);
}

char *ft_verify(char *tmp, char *buff)
{
	char *str_dup;
	int len;

	str_dup = NULL;
	len = 0;
	if (tmp)
	{
		str_dup = ft_strdup(tmp);
		free(tmp);
		len = ft_strlen( str_dup) + ft_strlen(buff);
		tmp = (char*)malloc(len + 1);
		if(!tmp)
			return (NULL);
		tmp = ft_strjoin(str_dup, buff);
		free(str_dup);
	}
	else if (!tmp)
		tmp = ft_strdup(buff);
	return (tmp);
}
void	ft_extract(char **ptr)
{
	char *str_dup;
	str_dup = ft_strdup(ft_strchr(*ptr, '\n') + 1);
	free(*ptr);
	*ptr = str_dup;
}
char *ft_free(char **ptr_tmp, char **ptr_buff, ssize_t null)
{
	char	*line;
	
	line = NULL;
	if (*ptr_tmp && **ptr_buff && null == 0)
	{
		line = ft_strdup(*ptr_tmp);
		free(*ptr_tmp);
		*ptr_tmp = NULL;
		free(*ptr_buff);
		*ptr_buff = NULL;
		return (line);
	}
	if (ft_strchr(*ptr_tmp, '\n'))
	{
		line = ft_substr(*ptr_tmp, 0, (ft_strlen(*ptr_tmp) - ft_strlen(ft_strchr(*ptr_tmp, '\n'))) + 1);
		ft_extract(ptr_tmp);
		return (line);
	}
	return (line);
	
}

char *get_next_line(int fd)
{
	static char	*tmp;
	char		*buff;
	char		*line;
	ssize_t		null;

	line = NULL;
	buff = NULL;
	null = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while(null != 0)
	{
		if (!(ft_strchr(tmp, '\n')))
			return (ft_free(&tmp, &buff, null));
		buff = (char *)malloc(BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		null = read(fd, buff, BUFFER_SIZE);
		if (null <= 0)
			break;
		tmp = ft_verify(tmp, buff);
		free(buff);
		buff = NULL;
	}
	return (ft_free(&tmp, &buff, null));
}
