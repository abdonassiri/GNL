/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnassir <abnassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 22:19:55 by abnassir          #+#    #+#             */
/*   Updated: 2025/12/25 16:23:51 by abnassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_tmp(char **tmp)
{
	char	*ln;
	char	*guard;
	char	*end;

	ln = NULL;
	end = ft_strchr(*tmp, '\n');
	if (end != NULL)
	{
		ln = ft_substr (*tmp, 0, ft_strlen(*tmp) - ft_strlen(end + 1));
		guard = *tmp;
		*tmp = ft_substr (*tmp, ft_strlen(ln), ft_strlen(*tmp) - ft_strlen(ln));
		free(guard);
	}
	else
	{
		ln = ft_strdup(*tmp);
		free(*tmp);
		*tmp = NULL;
	}
	return (ln);
}

char	*get_next_line(int fd)
{
	char			*buff;
	static char		*tmp;
	char			*ln;
	ssize_t			read_return;

	ln = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	while ((ft_strchr(tmp, '\n')) == NULL)
	{
		buff = malloc((size_t)BUFFER_SIZE + 1);
		if (!buff)
			return (NULL);
		read_return = read(fd, buff, BUFFER_SIZE);
		if (read_return <= 0)
		{
			free(buff);
			break ;
		}
		buff[read_return] = '\0';
		tmp = ft_strjoin(tmp, buff);
		free(buff);
	}
	ln = ft_tmp(&tmp);
	return (ln);
}
