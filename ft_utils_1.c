/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:03:06 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 08:42:53 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// if is % just print it and return
int	print_percent(const char *format, int index)
{
	while (is_included("cspdiuxX%", format[index]) == -1)
		index++;
	if (format[index] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
}

int	print_char(const char *format, int index, va_list par_list)
{
	while (is_included("cspdiuxX%", format[index]) == -1)
		index++;
	if (format[index] == 'c')
	{
		ft_putchar_fd(va_arg(par_list, int), 1);
		return (1);
	}
	return (0);
}

char	*print_str(va_list par_list, const char *format, int index)
{
	char	*result;
	int		f_width;
	int		is_full_stop;

	f_width = -1;
	is_full_stop = is_fstop(format, index, &f_width, par_list);
	result = va_arg(par_list, char *);
	if (!result)
		return (ft_strdup("(null)"));
	if (is_full_stop)
		return (ft_substr(result, 0, f_width));
	return (ft_strdup(result));
}

char	*print_i_d(va_list par_list, const char *format, int index)
{
	int		num;
	char	*result;
	char	*temp;

	num = va_arg(par_list, int);
	if (num < 0 || !(is_plus_f(format, index) || is_space_f(format, index)))
		return (ft_itoa(num));
	temp = ft_itoa(num);
	if (is_plus_f(format, index))
		result = ft_strjoin("+", temp);
	else
		result = ft_strjoin(" ", temp);
	if (temp)
		free(temp);
	return (result);
}

// checks if c is included on str.
// If yes, return its position, otherwise return -1.
int	is_included(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		if (c == str[i])
			return (i);
		i++;
	}
	return (-1);
}
