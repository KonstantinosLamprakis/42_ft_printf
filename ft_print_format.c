/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 08:22:04 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_result(const char *format, int index, va_list par_list);
int			check_remeinder(const char *format, int index, va_list par_list);

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
	int	temp_ind;

	temp_ind = index;
	while (is_included("cspdiuxX%", format[temp_ind]) == -1)
		temp_ind++;
	if (format[temp_ind] == 's')
		return (print_str(par_list));
	else if (format[temp_ind] == 'p')
		return (print_ptr(par_list));
	else if (format[temp_ind] == 'i' || format[temp_ind] == 'd')
		return (print_i_d(par_list));
	else if (format[temp_ind] == 'u')
		return (print_u(par_list));
	else if (format[temp_ind] == 'x' || format[temp_ind] == 'X')
		return (print_x(par_list, format[temp_ind], is_hash_f(format, index)));
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
	is_f_stop = is_fstop(format, index, &f_width, par_list);
	printf("\nfull stop: %d, width: %d\n", is_fstop(format, index, &f_width, par_list), f_width);

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

	return (0);
}

// need to implement rules here to print the prefix-postfix of value
// -0.# +

// ________________

// The remainder of the format specification includes, in the following order:

// if %x or %X
// {
// 	check for # and print 0x or 0X
// }
// 	# : value should be printed in an ``alternate form''
// 		For c, d, s and u formats, this option has no effect.
// 		For x (X) format, a non-zero result has the string 0x (0X) prepended to it.

// if (%d or %i) and > 0
// {
// 	if '+' put +
// 	else if ' ' put ' '
// }
// 	+ : specifying that there should always be a sign placed before the number when using signed formats
// 	' ': space specifying that a blank should be left before a positive number for a signed format. A `+' overrides a space if both are used;

// (2)if '-'
// 	left_ajs_with_blank
	// put width - strlen(result)
	// put result
// else if '0'
// 	right_ajs_with_0
	// put result
	// put width - strlen(result)
// else
// 	right_ajs_with_blank
// 	- : specifies left adjustment of the output in the indicated field
// 	0 : zero-padding should be used rather than blank-padding. A `-' overrides a `0' if both are used;

// if width != -1
	// if width > strlen(result)
	// (2)
// Field Width:
// 	An optional digit string specifying a field width
// 		if the output string has fewer bytes than the field width it will be blank-padded on the left (or right, if the left adjustment indicator has been given)
// 		to make up the field width (note that a leading zero is a flag, but an embedded zero is part of a field width);
// 	A field width or precision may be `*' instead of a digit string.  In this case an argument supplies the field width or precision.

// if %s
// {
// 	check for '.' and print at most len width digits or zero if width = -1
// }
// Precision:
// 	An optional period, `.', followed by an optional digit string giving a precision which specifies the maximum number of bytes to be printed from a string;
// 	if the digit string is missing, the precision is treated as zero;
// 	A field width or precision may be `*' instead of a digit string.  In this case an argument supplies the field width or precision.

// ________________
