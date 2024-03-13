/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:45:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 17:31:38 by klamprak         ###   ########.fr       */
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
// 	c = ft_printf(" %.2u\n", 1);
// 	b = printf(" %.2u\n", 1);

// 	printf("-%d %d-\n", c , b);
// 	// system("leaks a.out");
// }
