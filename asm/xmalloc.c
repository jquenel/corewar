/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xmalloc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 01:49:15 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/23 18:52:15 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdlib.h>
#include <unistd.h>
#include "xmalloc.h"

void	*xmalloc(size_t size)
{
	void	*ret;

	if ((ret = malloc(size)) == NULL && size != 0)
		die_oom();
	return (ret);
}

void	die_oom(void)
{
	ft_dprintf(STDERR_FILENO, "Out of memory.\n");
	exit(127);
}
