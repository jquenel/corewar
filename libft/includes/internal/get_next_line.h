/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:15:20 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/22 13:57:29 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 1024

# include <stddef.h>

typedef struct	s_fd_data
{
	int		fd;
	size_t	size;
	char	*data;
}				t_fd_data;

int				get_next_line_aux(t_fd_data *fd_data, char **line);

#endif
