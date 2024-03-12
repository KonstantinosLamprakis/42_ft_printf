/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_result.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:42:06 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 09:57:38 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_result(const char *format, int index, va_list par_list)
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
