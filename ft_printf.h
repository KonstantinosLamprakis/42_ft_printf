/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 16:26:55 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 19:22:21 by klamprak         ###   ########.fr       */
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
// declarations of ft_get_result.c
char	*get_result(const char *format, int index, va_list par_list);
// declarations of ft_utils_2.c
char	*print_x(va_list par_list, char c);
char	*print_ptr(va_list par_list);
char	*print_u(va_list par_list);
// declarations of ft_get_hex.c
int		count_digits(t_u_long num, int base);
void	get_hex(t_u_long nbr, int is_up_case, char *result, int is_int);
void	str_revert(char *str);
// declarations of ft_utils_1.c
int		print_char(const char *format, int index, va_list par_list);
char	*print_str(va_list par_list);
char	*print_i_d(va_list par_list);
int		print_percent(const char *format, int index);
int		is_included(const char *str, char c);
#endif
