/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:26:55 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 08:25:30 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	<stdarg.h>: va_start, va_arg, va_copy, va_end
*/

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>

typedef unsigned long long	t_u_long;

// declarations of ft_printf.c
int		ft_printf(const char *format, ...);
// declarations of ft_print_format.c
int		print_format(const char *format, int ind, va_list par_l, int *ch_num);
// declarations of ft_utils_2.c
char	*print_x(va_list par_list, char c, int is_hash);
char	*print_ptr(va_list par_list);
char	*print_u(va_list par_list);
// declarations of ft_get_hex.c
int		count_digits(t_u_long num, int base);
void	get_hex(t_u_long nbr, int is_up_case, char *result, int is_int);
void	str_revert(char *str);
// declarations of ft_utils_1.c
int		print_char(const char *format, int index, va_list par_list);
char	*print_str(va_list par_list);
char	*print_i_d(va_list par_list, const char *format, int index);
int		print_percent(const char *format, int index);
int		is_included(const char *str, char c);
// declarations of ft_utils_bonus.c
int		is_minus_f(const char *format, int index);
int		is_zero_padding(const char *format, int index);
// declarations of ft_utils_2_bonus.c
int		is_plus_f(const char *format, int index);
int		is_space_f(const char *format, int index);
int		is_hash_f(const char *format, int index);
int		is_fstop(const char *format, int index, int *f_width, va_list par_list);
int		get_field_width(const char *format, int index, va_list par_list);
#endif
