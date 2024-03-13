/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:45:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 13:46:33 by klamprak         ###   ########.fr       */
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

#include <limits.h>
int	main(void)
{
	int b, c;
	char *test = "this is me";

	b = 0;
	c = 0;
	// printf("%15.*s", 5, "this is a test");
	// printf("% d", 5);
	// printf("%3d", 1243);

	c = ft_printf("%010.2i\n", -8473);
	b = printf("%010.2i\n", -8473);

	printf("-%d %d-\n", c , b);
	// system("leaks a.out");
}

// b = printf("%08.4d\n", -14);

// c = ft_printf(">------------<%58.24d>------------<\n", 0);
// b = printf(">------------<%58.24d>------------<\n", 0);

// c = ft_printf("%08.3i\n", -8473);
// b = printf("%08.3i\n", -8473);

// . adds zeros in front of number like d i u not spase
// . put after the zeros the minus while field_width before
// . ensure the number to have the exact size without the sign,
	// not the whole thing
// field width ensures the minus is before space
	// or after zero if its a number
// ("%.s", NULL) -> should print only "" not (null)
	// if negative number, zero go between minus and number until reach width..if . exists overatis 0 with " "
// if is ' ' filled before '-' on negative while if is '0' filled after the minus
// pressision always filled with zeros no matter what

