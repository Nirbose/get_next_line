/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ltuffery <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 12:17:30 by ltuffery          #+#    #+#             */
/*   Updated: 2022/10/17 00:41:14 by ltuffery         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str;

	fd1 = open("./tests/41_no_nl", O_RDONLY);
	fd2 = open("./tests/test2", O_RDONLY);
	fd3 = open("./tests/test3", O_RDONLY);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	str = get_next_line(fd1);
	printf("%s", str);
	free(str);
	close(fd1);
	close(fd2);
	close(fd3);
}
