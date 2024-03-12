/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:03:06 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 09:37:34 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_char(va_list par_list)
{
	char	*result;

	result = malloc(sizeof(char));
	if (!result)
		return (NULL);
	result[0] = (char) va_arg(par_list, int);
	return (result);
}

char	*print_str(va_list par_list)
{
	char	*result;

	result = va_arg(par_list, char *);
	if (!result)
		return (ft_strdup("(null)"));
	return (ft_strdup(result));
}

char	*print_i_d(va_list par_list)
{
	return (ft_itoa(va_arg(par_list, int)));
}

// if is % just print it and return
int	print_percent(const char *format, int index)
{
	if (format[index] == '%')
	{
		ft_putchar_fd('%', 1);
		return (1);
	}
	return (0);
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
