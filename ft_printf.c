/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 07:45:41 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/11 10:46:22 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// TODO: check the return value of printf
// cc *.c *.h */*.c */*.h && ./a.out | cat -e

#include "ft_printf.h"

static int	get_par_num(const char *format);
static int	is_included(const char *str, char c);
static int	get_escape(const char *s, int index);

int	ft_printf(const char *format, ...)
{
	int		par_num;
	va_list	par_list;
	int		i;
	char	c;

	par_num = get_par_num(format);
	va_start(par_list, format);
	i = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '\\')
		{
			c = get_escape(format, i);
			if (c != -1)
				ft_putchar_fd((char)c, 1);
		}
		else if (format[i] == '%')
		{
			i++;
			continue;
		}
		else
		{
			ft_putchar_fd(format[i], 1);
			// printf("%c", format[i]);
			// write(1, &format[i], sizeof(char));
		}
		i++;
	}
	// while (i < par_num)
	// {
	// 	// puts(ft_itoa(va_arg(par_list, int)));
	// 	i++;
	// }
	// va_end(par_list);
	return (0);
}

// get the number of parameters expected from f(printf's first arg)
static int	get_par_num(const char *format)
{
	int	i;
	int	num;

	i = 0;
	num = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && is_included("cspdiuxX%", format[i + 1]) != -1)
			num++;
		i++;
	}
	return (num);
}

// checks if c is included on str.
// If yes, return its position, otherwise return -1.
static int	is_included(const char *str, char c)
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

// returns ascci code of escape char sequense, which is at s[index]
static int	get_escape(const char *s, int index)
{
	int	i;
	int	ascii_vals_arr[10];

	ascii_vals_arr[0] = 7;
	ascii_vals_arr[1] = 8;
	ascii_vals_arr[2] = 0;
	ascii_vals_arr[3] = 12;
	ascii_vals_arr[4] = 10;
	ascii_vals_arr[5] = 13;
	ascii_vals_arr[6] = 9;
	ascii_vals_arr[7] = 11;
	ascii_vals_arr[8] = 39;
	ascii_vals_arr[9] = 92;
	if (s[index] != '\\')
	{
		i = is_included("abcfnrtv'\\", s[index + 1]);
		if (i != -1)
			return (ascii_vals_arr[i]);
	}
	return (-1);
}

// int	main(void)
// {
// 	char const *str = "this \\ is a test\n";

// 	printf(str);
// 	ft_printf(str);
// 	// ft_printf("%d fads %d", 5, -10);
// }

