/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: merlich <merlich@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/28 20:46:55 by merlich           #+#    #+#             */
/*   Updated: 2021/12/28 21:03:03 by merlich          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "fdf.h"

int	main(void)
{
	int		fd;
	char	*line;

	fd = open("/Users/merlich/Documents/FDF_git/test_maps 2/julia.fdf", O_RDONLY);
	line = get_next_line(fd);
	while (line)
	{
		printf("%s", line);
		line = get_next_line(fd);
	}
	close (fd);
	return (0);
}
