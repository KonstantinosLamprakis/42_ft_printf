/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:03:09 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 09:11:16 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_ptr(va_list par_list)
{
	par_list = NULL;
	return (NULL);
}

char	*print_u(va_list par_list)
{
	par_list = NULL;
	return (NULL);
}

char	*print_x(va_list par_list, char x)
{
	int		num;
	char	*temp;
	char	*result;

	num = va_arg(par_list, int);
	temp = ft_putnbr_base(num, "0123456789ABCDEF");
	result = ft_strjoin("0x", temp);
	if (temp)
		free(temp);
	if (x == 'X')
		result[1] = 'X';
	return (result);
}
