/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/04 20:09:12 by sboilard          #+#    #+#             */
/*   Updated: 2017/12/15 01:23:13 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUFFER_H
# define BUFFER_H

# include <stddef.h>
# include <wchar.h>

# define BUFF_SIZE 1024

typedef struct	s_buffer
{
	size_t	offset;
	size_t	written;
	int		fd;
	char	buffer[BUFF_SIZE];
}				t_buffer;

void			init_buffer(t_buffer *buffer, int fd);
void			flush_buffer(t_buffer *buffer);
void			putchar_buffer(t_buffer *buffer, char c);
void			putnchar_buffer(t_buffer *buffer, char c, int count);
void			putstr_buffer(t_buffer *buffer, const char *str);
void			putnstr_buffer(t_buffer *buffer, const char *str, size_t len);
void			putnwstr_buffer(t_buffer *buffer, const wchar_t *str,
								size_t mblen);

#endif
