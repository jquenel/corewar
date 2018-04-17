/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_aux.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 16:52:00 by sboilard          #+#    #+#             */
/*   Updated: 2018/01/04 21:07:59 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "internal/get_next_line.h"
#include "libft_str.h"

static char	*pop_data(t_fd_data *fd_data, const char *split)
{
	size_t	line_size;
	size_t	rem_size;
	char	*line;
	char	*rem;

	line_size = split - fd_data->data;
	rem_size = fd_data->size - line_size;
	line = (char *)malloc(line_size);
	if (line == NULL)
		return (NULL);
	rem = rem_size > 0 ? (char *)malloc(rem_size) : NULL;
	if (rem == NULL && rem_size > 0)
	{
		free(line);
		return (NULL);
	}
	ft_memcpy(line, fd_data->data, line_size - 1);
	line[line_size - 1] = '\0';
	ft_memcpy(rem, fd_data->data + line_size, rem_size);
	free(fd_data->data);
	fd_data->size = rem_size;
	fd_data->data = rem;
	return (line);
}

static int	push_data(t_fd_data *fd_data, const char *buffer, size_t size)
{
	char	*tmp;

	if (size == 0)
		return (1);
	tmp = ft_memjoin(fd_data->data, fd_data->size, buffer, size);
	if (tmp == NULL)
		return (0);
	free(fd_data->data);
	fd_data->data = tmp;
	fd_data->size += size;
	return (1);
}

static int	perform_reads(t_fd_data *fd_data, char **found_out)
{
	char	buffer[BUFF_SIZE];
	char	*found;
	int		read_size;

	read_size = 0;
	while ((found = ft_memchr(buffer, '\n', read_size)) == NULL)
	{
		read_size = read(fd_data->fd, buffer, BUFF_SIZE);
		if (read_size < 0)
			return (-1);
		if (read_size == 0)
		{
			if (fd_data->data == NULL)
				return (0);
			buffer[0] = '\n';
			read_size = 1;
		}
		if (!push_data(fd_data, buffer, read_size))
			return (-1);
	}
	*found_out = fd_data->data + fd_data->size - read_size + (found - buffer);
	return (1);
}

int			get_next_line_aux(t_fd_data *fd_data, char **line)
{
	char	*found;
	int		ret;

	found = ft_memchr(fd_data->data, '\n', fd_data->size);
	if (found == NULL)
	{
		ret = perform_reads(fd_data, &found);
		if (ret <= 0)
			return (ret);
	}
	*line = pop_data(fd_data, found + 1);
	if (*line == NULL)
		return (-1);
	return (1);
}
