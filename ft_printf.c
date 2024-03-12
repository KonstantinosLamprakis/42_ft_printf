/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:45:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 14:32:27 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: check the return value of printf
// TODO: \num
// return -1 if write failed
// cc *.c *.h */*.c */*.h && ./a.out | cat -e

#include "ft_printf.h"

// returns how many characters printed
int	ft_printf(const char *format, ...)
{
	va_list	par_list;
	int		i;
	int		printed_num;

	va_start(par_list, format);
	i = 0;
	printed_num = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%')
			i = print_format(format, i + 1, par_list, &printed_num);
		else
		{
			ft_putchar_fd(format[i], 1);
			printed_num++;
		}
		if (i == -1)
			return (-1);
		i++;
	}
	va_end(par_list);
	return (printed_num);
}

// #include <limits.h>
// int	main(void)
// {
// 	int b, c;

// 	b = 0;
// 	c = 0;
// 	c = ft_printf(" %x %x %x %x %x %x %x\n");
// 	// b = printf(" %x %x %x %x %x %x %x\n");
// 	// printf("-%d %d-\n", c , b);
// 	// system("leaks a.out");
// 	// 7fffffff 80000000 ffffffff fffffff0 ffffffff fffffff0 ffffffd6$
// }
