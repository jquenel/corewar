/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:09:15 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 00:51:04 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "buffer.h"

void	init_buffer(t_buffer *buffer, int fd)
{
	buffer->offset = 0;
	buffer->written = 0;
	buffer->fd = fd;
}

void	flush_buffer(t_buffer *buffer)
{
	write(buffer->fd, buffer->buffer, buffer->offset);
	buffer->written += buffer->offset;
	buffer->offset = 0;
}
