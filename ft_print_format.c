/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 07:18:21 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_result(const char *format, int index, va_list par_list);
int	check_remeinder(const char *format, int index, va_list par_list);

// ind = current index on format, start from first char after %
// return the index of last character that got processed
// ch_num keep score of how many character printed
int	print_format(const char *format, int ind, va_list par_l, int *ch_num)
{
	char	*result_str;

	check_remeinder(format, ind, par_l);
	return (0);
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

int	check_remeinder(const char *format, int index, va_list par_list)
{
	int	is_minus;
	int	is_zer_pad;
	int	is_f_stop;
	int	f_width;
	int	field_width;
	int	is_hash;
	int	is_space;
	int	is_plus;

	printf("test");
	is_f_stop = is_full_stop(format, index, &f_width, par_list);
	printf("\nfull stop: %d, width: %d\n", is_full_stop(format, index, &f_width, par_list), f_width);

	is_minus = is_minus_f(format, index);
	printf("minus: %d\n", is_minus_f(format, index));

	is_plus = is_plus_f(format, index);
	printf("plus: %d\n", is_plus_f(format, index));

	is_zer_pad = is_zero_padding(format, index);
	printf("zero padding: %d\n", is_zero_padding(format, index));

	field_width = get_field_width(format, index, par_list);
	printf("field width: %d\n", get_field_width(format, index, par_list));

	is_hash = is_hash_f(format, index);
	printf("hash: %d\n", is_hash_f(format, index));

	is_space = is_space_f(format, index);
	printf("space: %d\n", is_space_f(format, index));

	// need to implement rules here to print the prefix-postfix of value
	// -0.# +
	return (0);
}
