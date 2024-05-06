/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 02:18:40 by legrandc          #+#    #+#             */
/*   Updated: 2024/05/06 03:06:52 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

char	*get_next_line(int fd)
{
	t_vars		v;
	static char	s[BUFFER_SIZE + 1] = {0};

	free((v.r = 1, v.s = NULL, v.len = 0, NULL));
	while (v.r > 0)
	{
		v.tmp = malloc((v.r = -1, v.len + BUFFER_SIZE + 1));
		if (!v.tmp)
			return (free(v.s), NULL);
		while (v.s && v.s[++v.r])
			v.tmp[v.r] = v.s[v.r];
		free((free((v.tmp[v.r + !v.s] = 0, v.r = -1, v.s)), v.s = v.tmp, NULL));
		while (s[++v.r] && s[v.r - 1] != '\n')
			v.s[v.len++] = s[v.r];
		v.s[v.len] = 0;
		if (s[v.r - 1] == '\n')
			break ;
		free((v.r = read(fd, s, BUFFER_SIZE), s[v.r] = 0, NULL));
	}
	if (v.r == -1 || v.len == 0)
		return (free(v.s), NULL);
	v.len = -1;
	while (s[v.r + ++v.len])
		s[v.len] = s[v.r + v.len];
	return (s[v.len] = 0, v.s);
}

// #include <fcntl.h>
// #include <stdio.h>

// int	main(int ac, char **av)
// {
// 	char	*line;
// 	int		fd;

// 	fd = open(av[1], O_RDONLY);
// 	while ((line = get_next_line(fd)))
// 	{
// 		printf("[%s]", line);
// 		free(line);
// 	}
// 	printf("[%s]", line);
// 	free(line);
// 	close(fd);
// 	return (0);
// }
