/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abnassir <abnassir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/24 21:18:33 by abnassir          #+#    #+#             */
/*   Updated: 2025/12/25 14:30:46 by abnassir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i])
	{
		if (s[i] == (unsigned char)c)
			return ((char *)(s + i));
		i++;
	}
	if (s[i] == (unsigned char)c)
		return ((char *)(s + i));
	return (NULL);
}

char	*ft_strdup(const char *source_str)
{
	size_t	i;
	size_t	len;
	char	*new_str;

	i = 0;
	if (!source_str)
		return (NULL);
	len = ft_strlen(source_str);
	new_str = (char *)malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	while (i <= len)
	{
		new_str[i] = source_str[i];
		i++;
	}
	return (new_str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	s_len;
	char	*sub;

	i = 0;
	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	if (!len || s_len <= start)
		return (ft_strdup(""));
	if (start + len <= s_len)
		sub = (char *)malloc(len + 1);
	else
		sub = (char *)malloc(s_len - start + 1);
	if (sub == NULL)
		return (NULL);
	while (start + i < s_len && i < len)
	{
		sub[i] = s[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		t;
	size_t	j;
	char	*new;

	i = 0;
	j = 0;
	t = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(t + 1);
	if (new == NULL)
		return (NULL);
	while (j < ft_strlen(s1))
		new[i++] = s1[j++];
	j = 0;
	while (j < ft_strlen(s2))
		new[i++] = s2[j++];
	new[i] = '\0';
	free((char *)s1);
	return (new);
}
