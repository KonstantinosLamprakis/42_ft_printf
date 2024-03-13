/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 06:29:21 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 06:39:32 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_minus_f(const char *format, int index)
{
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] == '-')
			return (1);
		index++;
	}
	return (0);
}

int	is_zero_padding(const char *format, int index)
{
	int	is_first_num;

	is_first_num = 1;
	while (is_included("cspdiuxX%", format[index]) == -1)
	{
		if (format[index] > '0' && format[index] <= '9')
			is_first_num = 0;
		if (format[index] == '0' && is_first_num)
			return (1);
		index++;
	}
	return (0);
}
