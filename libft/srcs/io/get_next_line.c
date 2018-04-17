/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 15:15:22 by sboilard          #+#    #+#             */
/*   Updated: 2018/01/04 21:01:16 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "internal/get_next_line.h"
#include "libft_hashtable.h"

static t_fd_data	*make_fd_data(int fd)
{
	t_fd_data	*fd_data;

	fd_data = (t_fd_data *)malloc(sizeof(*fd_data));
	if (fd_data == NULL)
		return (NULL);
	fd_data->fd = fd;
	fd_data->size = 0;
	fd_data->data = NULL;
	return (fd_data);
}

static void			destroy_fd_data(t_fd_data *fd_data)
{
	free(fd_data->data);
	free(fd_data);
}

int					get_next_line(int fd, char **line)
{
	static t_hashtable	*fd_hashtable = NULL;
	t_fd_data			*fd_data;
	int					ret;

	if (fd_hashtable == NULL)
	{
		fd_hashtable = ft_hashtable_make(ft_hashfun_int, ft_compfun_int, 8);
		if (fd_hashtable == NULL)
			return (-1);
	}
	fd_data = ft_hashtable_find(fd_hashtable, &fd);
	if (fd_data == NULL)
	{
		fd_data = make_fd_data(fd);
		if (fd_data == NULL)
			return (-1);
		ft_hashtable_insert(fd_hashtable, fd_data);
	}
	ret = get_next_line_aux(fd_data, line);
	if (ret <= 0)
	{
		ft_hashtable_remove(fd_hashtable, &fd);
		destroy_fd_data(fd_data);
	}
	return (ret);
}
