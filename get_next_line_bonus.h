/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: legrandc <legrandc@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 02:18:00 by legrandc          #+#    #+#             */
/*   Updated: 2024/05/06 02:45:12 by legrandc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 45
# endif

# define MAXFD 512

typedef struct s_vars
{
	char	*s;
	size_t	len;
	ssize_t	r;
	char	*tmp;
}			t_vars;

char		*get_next_line(int fd);

#endif
