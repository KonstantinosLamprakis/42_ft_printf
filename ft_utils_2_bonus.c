/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:34:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 07:20:09 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_field_width(const char *format, int index, va_list par_list)
{
	int	temp;
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] == '.')
			return (-1);
		if (format[index] == '0' && !ft_isdigit(format[index - 1]))
		{
			index++;
			continue ;
		}
		temp = index;
		while (format[temp] >= '0' && format[temp] <= '9')
			temp++;
		if (index < temp)
			return (ft_atoi(ft_substr(format, index, temp - index)));
		else if (format[temp] == '*')
			return (va_arg(par_list, int));
		index++;
	}
	return (-1);
}

int	is_full_stop(const char *format, int index, int *f_width, va_list par_list)
{
	int	is_f_stop;
	int	temp;

	is_f_stop = 0;
	*f_width = -1;
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] == '.')
		{
			index++;
			temp = index;
			while (format[temp] >= '0' && format[temp] <= '9')
				temp++;
			if (index < temp)
				*f_width = ft_atoi(ft_substr(format, index, index - temp));
			else if (format[temp] == '*')
				*f_width = va_arg(par_list, int);
			return (1);
		}
		index++;
	}
	return (0);
}

int	is_hash_f(const char *format, int index)
{
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] == '#')
			return (1);
		index++;
	}
	return (0);
}

int	is_space_f(const char *format, int index)
{
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] == ' ')
			return (1);
		index++;
	}
	return (0);
}

int	is_plus_f(const char *format, int index)
{
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] == '+')
			return (1);
		index++;
	}
	return (0);
}
