/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:10:41 by ltuffery          #+#    #+#             */
/*   Updated: 2022/10/11 19:34:16 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	size_t			i;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if ((int)nmemb < 0 && (int)size < 0)
		return (NULL);
	tab = malloc(nmemb * size);
	i = 0;
	if (tab == NULL)
		return (NULL);
	while (i < (nmemb * size))
	{
		tab[i] = '\0';
		i++;
	}
	return ((void *)tab);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*str;
	int			line_len;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buffer == NULL)
		return (NULL);
	if (read(fd, buffer, BUFFER_SIZE) == 0)
	{
		if (str != NULL)
			free(str);
		return (NULL);
	}
	if (str == NULL)
		str = ft_calloc(1, sizeof(char));
	if (str == NULL)
		return (NULL);
	str = ft_strjoin(str, buffer);
	while (str[line_len] != '\0' && str[line_len] != '\n')
		line_len++;
	line = ft_calloc((line_len + 2), sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, str, line_len + 2);
	str = ft_substr(str, line_len + 1, ft_strlen(str) - (line_len + 2));
	return (line);
}
