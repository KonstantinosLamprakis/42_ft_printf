/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:45:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 07:21:08 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// cc *.c *.h */*.c */*.h && ./a.out | cat -e
// check norminette with table asigments "0123456789"

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
// 	char *test = "this is me";

// 	b = 0;
// 	c = 0;
// 	ft_printf("%012.*d", 4, 8);
// 	// c = ft_printf(" %p %p\n", LONG_MIN, LONG_MAX);
// 	// b = printf(" %p %p\n", LONG_MIN, LONG_MAX);
// 	// printf("-%d %d-\n", c , b);
// 	// system("leaks a.out");
// }
