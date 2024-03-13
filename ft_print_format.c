/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 09:08:07 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_result(const char *format, int index, va_list par_list);

// ind = current index on format, start from first char after %
// return the index of last character that got processed
// ch_num keep score of how many character printed
int	print_format(const char *format, int ind, va_list par_l, int *ch_num)
{
	char	*result_str;
	int		format_width;
	int		field_width;
	int		i;

	if (print_percent(format, ind) || print_char(format, ind, par_l))
	{
		(*ch_num)++;
		return (ind);
	}
	result_str = get_result(format, ind, par_l);
	if (result_str)
	{
		format_width = ft_strlen(result_str);
		field_width = get_field_width(format, ind, par_l);
		if (field_width > format_width)
		{
			if (is_minus_f(format, ind))
			{
				ft_putstr_fd(result_str, 1);
				i = 0;
				while (i++ < field_width - format_width)
					ft_putchar_fd(' ', 1);
			}
			else if (is_zero_padding(format, ind))
			{
				i = 0;
				while (i++ < field_width - format_width)
					ft_putchar_fd('0', 1);
				ft_putstr_fd(result_str, 1);
			}
			else
			{
				i = 0;
				while (i++ < field_width - format_width)
					ft_putchar_fd(' ', 1);
				ft_putstr_fd(result_str, 1);
			}
			*ch_num += field_width - format_width;
		}
		else
			ft_putstr_fd(result_str, 1);
		// if (format[ind] != 'c')
		*ch_num += format_width;
		// else
		// 	*ch_num += 1;
		free(result_str);
	}
	else
		return (-1);
	while (is_included("cspdiuxX%", format[ind]) == -1)
		ind++;
	return (ind);
}

static char	*get_result(const char *format, int index, va_list par_list)
{
	int	temp_ind;

	temp_ind = index;
	while (is_included("cspdiuxX%", format[temp_ind]) == -1)
		temp_ind++;
	if (format[temp_ind] == 's')
		return (print_str(par_list, format, index));
	else if (format[temp_ind] == 'p')
		return (print_ptr(par_list));
	else if (format[temp_ind] == 'i' || format[temp_ind] == 'd')
		return (print_i_d(par_list, format, index));
	else if (format[temp_ind] == 'u')
		return (print_u(par_list));
	else if (format[temp_ind] == 'x' || format[temp_ind] == 'X')
		return (print_x(par_list, format[temp_ind], is_hash_f(format, index)));
	return (NULL);
}
