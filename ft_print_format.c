/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 06:24:58 by klamprak         ###   ########.fr       */
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

	if (print_percent(format, ind) || print_char(format, ind, par_l))
	{
		(*ch_num)++;
		return (ind);
	}
	result_str = get_result(format, ind, par_l);
	if (result_str)
	{
		ft_putstr_fd(result_str, 1);
		if (format[ind] != 'c')
			*ch_num += ft_strlen(result_str);
		else
			*ch_num += 1;
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
	while (is_included("cspdiuxX%", format[index]) == -1)
		index++;
	if (format[index] == 's')
		return (print_str(par_list));
	else if (format[index] == 'p')
		return (print_ptr(par_list));
	else if (format[index] == 'i' || format[index] == 'd')
		return (print_i_d(par_list));
	else if (format[index] == 'u')
		return (print_u(par_list));
	else if (format[index] == 'x' || format[index] == 'X')
		return (print_x(par_list, format[index]));
	return (NULL);
}
