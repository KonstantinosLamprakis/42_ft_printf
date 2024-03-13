/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 09:23:02 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_result(const char *format, int index, va_list par_list);
static int	pr_res(char *res_str, const char *format, int ind, va_list par_l);
static void	print_alignment(char *result_str, int len, char c, int is_left);

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
		*ch_num += pr_res(result_str, format, ind, par_l);
	else
		return (-1);
	while (is_included("cspdiuxX%", format[ind]) == -1)
		ind++;
	return (ind);
}

static int	pr_res(char *res_str, const char *format, int ind, va_list par_l)
{
	int	format_width;
	int	field_width;
	int	i;
	int	result;

	result = 0;
	i = 0;
	format_width = ft_strlen(res_str);
	field_width = get_field_width(format, ind, par_l);
	if (field_width > format_width)
	{
		if (is_minus_f(format, ind))
			print_alignment(res_str, field_width - format_width, ' ', 1);
		else if (is_zero_padding(format, ind))
			print_alignment(res_str, field_width - format_width, '0', 0);
		else
			print_alignment(res_str, field_width - format_width, ' ', 0);
		result += field_width - format_width;
	}
	else
		ft_putstr_fd(res_str, 1);
	result += format_width;
	if (res_str)
		free(res_str);
	return (result);
}

static void	print_alignment(char *result_str, int len, char c, int is_left)
{
	int	i;

	i = 0;
	if (is_left)
	{
		ft_putstr_fd(result_str, 1);
		while (i++ < len)
			ft_putchar_fd(c, 1);
	}
	else
	{
		while (i++ < len)
			ft_putchar_fd(c, 1);
		ft_putstr_fd(result_str, 1);
	}
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
