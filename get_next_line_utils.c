/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 23:33:26 by ltuffery          #+#    #+#             */
/*   Updated: 2022/10/11 19:18:48 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s != NULL && s[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, int start, int len)
{
	char	*new_str;
	int		i;

	if (!s)
		return (NULL);
	if (start > ft_strlen(s))
	{
		new_str = malloc(1);
		new_str[0] = '\0';
		return (new_str);
	}
	if (ft_strlen(s) > len)
		new_str = ft_calloc((len + 1), sizeof(char));
	else
		new_str = ft_calloc((ft_strlen(s) - start + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	i = 0;
	while (i < len && start < ft_strlen(s) && s[start + i])
	{
		new_str[i] = s[start + i];
		i++;
	}
	new_str[i] = '\0';
	free((char *)s);
	return (new_str);
}

int	ft_strlcpy(char *dst, const char *src, int size)
{
	int	src_len;
	int	size_selected;
	int	i;

	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (src_len >= size)
		size_selected = size - 1;
	else
		size_selected = src_len;
	while (i < size_selected)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new_str;
	int		s1_len;
	int		s2_len;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	i = 0;
	new_str = ft_calloc((s1_len + s2_len + 1), sizeof(char));
	if (new_str == NULL)
		return (NULL);
	ft_strlcpy(new_str, s1, s1_len + 1);
	while (i < s2_len)
	{
		new_str[s1_len + i] = s2[i];
		i++;
	}
	new_str[s1_len + s2_len] = '\0';
	return (new_str);
}
