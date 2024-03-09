/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 10:33:21 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/07 13:23:02 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	positive_itoa(int n, char *result, int i);
static void	ft_itoa_no_mem(int n, char *result);

void	ft_putnbr_fd(int n, int fd)
{
	char	result[12];

	ft_itoa_no_mem(n, result);
	ft_putstr_fd(result, fd);
}

static void	ft_itoa_no_mem(int n, char *result)
{
	int		i;

	i = 0;
	if (n == -2147483648)
	{
		result[0] = '-';
		result[1] = '2';
		i += 2;
		n = 147483648;
	}
	if (n < 0)
	{
		result[i++] = '-';
		n = -n;
	}
	positive_itoa(n, result, i);
}

static void	positive_itoa(int n, char *result, int i)
{
	int		div;
	int		temp_num;

	temp_num = n;
	div = 1;
	while (temp_num / 10 != 0)
	{
		temp_num /= 10;
		div *= 10;
	}
	while (div >= 1)
	{
		result[i++] = '0' + (n / div);
		n %= div;
		div /= 10;
	}
	result[i++] = '\0';
}
