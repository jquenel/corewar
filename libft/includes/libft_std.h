/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_std.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sboilard <sboilard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 16:09:35 by sboilard          #+#    #+#             */
/*   Updated: 2018/04/04 22:18:00 by sboilard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STD_H
# define LIBFT_STD_H

# include <stddef.h>
# include <wchar.h>

int		ft_wctomb(char *str, wchar_t c);
int		ft_abs(int i);
int		ft_min(int n1, int n2);
int		ft_max(int n1, int n2);
int		ft_atoi(const char *str);
long	ft_atoi_base(const char *str, int base);
char	*ft_itoa(int n);
int		ft_int_of_string(const char *str, int *result);
int		ft_int_of_string_base(const char *str, int base, int *result);
int		ft_string_of_int(int num, char **result);

#endif
