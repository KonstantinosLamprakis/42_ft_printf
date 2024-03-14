/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/14 06:38:27 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*get_result(const char *format, int index, va_list par_list, int *flag);
static int	pr_res(char *res_str, const char *format, int ind, int field_width);
static void	print_alignment(char *result_str, int len, char c, int is_left);
static int	pr_null(const char *format, int ind, int field_width);
static int	not_fstop(const char *format, int ind);

// ind = current index on format, start from first char after %
// return the index of last character that got processed
// ch_num keep score of how many character printed
// flag for spesific case that need to print only one char, the \0
// also to mark if the result is a number
// also used flag as temp variable for other purposes
int	print_format(const char *format, int ind, va_list par_l, int *ch_num)
{
	char	*result_str;
	int		flag;
	int		field_width;

	field_width = get_field_width(format, ind, par_l);
	flag = ind;
	while (is_included("cspdiuxX%", format[flag]) == -1)
		flag++;
	if (format[flag] == 'c')
	{
		result_str = print_char(par_l, &flag);
		if (flag == -1)
			*ch_num += pr_null(format, ind, field_width);
		flag = 0;
	}
	else
		result_str = get_result(format, ind, par_l, &flag);
	if (result_str && flag && result_str[0] == '-')
	{
		ft_putchar_fd('-', 1);
		*ch_num += pr_res(result_str + 1, format, ind, field_width - 1) + 1;
	}
	else if (result_str)
		*ch_num += pr_res(result_str, format, ind, field_width);
	while (is_included("cspdiuxX%", format[ind]) == -1)
		ind++;
	if (result_str)
		free(result_str);
	return (ind);
}

// for spesific input, ("%c", 0) that need to print a single \0
static int	pr_null(const char *format, int ind, int field_width)
{
	int	format_width;
	int	i;
	int	result;

	result = 0;
	i = 0;
	format_width = 1;
	if (field_width > format_width)
	{
		if (is_minus_f(format, ind))
			print_alignment(NULL, field_width - format_width, ' ', 1);
		else if (is_zero_padding(format, ind))
			print_alignment(NULL, field_width - format_width, '0', 0);
		else
			print_alignment(NULL, field_width - format_width, ' ', 0);
		result += field_width - format_width;
	}
	else
		write(1, "", 1);
	result += format_width;
	return (result);
}

// print the result string
static int	pr_res(char *res_str, const char *format, int ind, int field_width)
{
	int	format_width;
	int	i;
	int	result;

	result = 0;
	i = 0;
	format_width = 0;
	if (res_str)
		format_width = ft_strlen(res_str);
	if (field_width > format_width)
	{
		if (is_minus_f(format, ind))
			print_alignment(res_str, field_width - format_width, ' ', 1);
		else if (is_zero_padding(format, ind) && not_fstop(format, ind))
			print_alignment(res_str, field_width - format_width, '0', 0);
		else
			print_alignment(res_str, field_width - format_width, ' ', 0);
		result += field_width - format_width;
	}
	else
		ft_putstr_fd(res_str, 1);
	result += format_width;
	return (result);
}

static int	not_fstop(const char *format, int ind)
{
	while (is_included("cspdiuxX%", format[ind]) == -1)
	{
		if (format[ind] == '.')
			return(0);
		ind++;
	}
	return (1);
}

// align the result that want to print properly
static void	print_alignment(char *result_str, int len, char c, int is_left)
{
	int	i;

	i = 0;
	if (is_left)
	{
		if (result_str)
			ft_putstr_fd(result_str, 1);
		else
			write(1, "", 1);
		while (i++ < len)
			ft_putchar_fd(c, 1);
	}
	else
	{
		while (i++ < len)
			ft_putchar_fd(c, 1);
		if (result_str)
			ft_putstr_fd(result_str, 1);
		else
			write(1, "", 1);
	}
}

static char	*get_result(const char *format, int index, va_list par_list, int *flag)
{
	int	temp_ind;

	temp_ind = index;
	*flag = 0;
	while (is_included("cspdiuxX%", format[temp_ind]) == -1)
		temp_ind++;
	if (format[temp_ind] == 's')
		return (print_str(par_list, format, index));
	else if (format[temp_ind] == '%')
		return (print_percent());
	else if (format[temp_ind] == 'p')
		return (print_ptr(par_list));
	else if (format[temp_ind] == 'i' || format[temp_ind] == 'd')
	{
		*flag = 1;
		return (print_i_d(par_list, format, index));
	}
	else if (format[temp_ind] == 'u')
		return (print_u(par_list, format, index));
	else if (format[temp_ind] == 'x' || format[temp_ind] == 'X')
		return (print_x(par_list, format[temp_ind], is_hash_f(format, index)));
	return (NULL);
}
