/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:34:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 16:26:38 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_field_width(const char *format, int index, va_list par_list)
{
	int		temp;
	char	*temp_str;

	while (is_included("cspdiuxX%.", format[index]) == -1)
	{
		index++;
		if (format[index - 1] == '0' && !ft_isdigit(format[index - 2]))
			continue ;
		index--;
		temp = index;
		while (format[temp] >= '0' && format[temp] <= '9')
			temp++;
		if (index < temp)
		{
			temp_str = ft_substr(format, index, temp - index);
			temp = ft_atoi(temp_str);
			if (temp_str)
				free(temp_str);
			return (temp);
		}
		else if (format[temp] == '*')
			return (va_arg(par_list, int));
		index++;
	}
	return (-1);
}

// f_width: how many bytes to read
// if no * or digits, shouldn't read any bytes
// return 1 if found a '.', 0 otherwise
int	is_fstop(const char *format, int index, int *f_width, va_list par_list)
{
	int	temp;
	char	*temp_str;

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
			{
				temp_str = ft_substr(format, index, temp - index);
				*f_width = ft_atoi(temp_str);
				if (temp_str)
					free(temp_str);
			}
			else if (format[temp] == '*')
				*f_width = va_arg(par_list, int);
			if (*f_width == -1)
				*f_width = 0;
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
