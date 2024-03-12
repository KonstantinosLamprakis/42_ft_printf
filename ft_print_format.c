/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 12:52:18 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 09:57:04 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
