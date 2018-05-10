/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/10 00:08:51 by sboilard          #+#    #+#             */
/*   Updated: 2018/05/10 00:17:01 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stddef.h>
# include "ast.h"

char	*get_output_filename(const char *filename);
size_t	instruction_size(const t_instruction_element *elem);
int		mnemo_id(const char *mnemo);

#endif
