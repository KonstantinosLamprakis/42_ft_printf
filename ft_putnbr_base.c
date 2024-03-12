/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:41:39 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/11 15:56:54 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	find_the_base(char *base_digits)
{
	int	i;

	i = 0;
	while (base_digits[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*calc_base(int n, char *str, int base)
{
	char	*result;
	int		i;
	int		sign;
	long	n_long;

	result = malloc(34 * sizeof(char));
	if (!result)
		return (NULL);
	n_long = n;
	i = 0;
	sign = 1;
	if (n_long < 0)
	{
		sign = -1;
		n_long = -n_long;
	}
	while (n_long > 0)
	{
		result[i++] = str[n_long % base];
		n_long = n_long / base;
	}
	if (sign == -1)
		result[i++] = '-';
	return (result);
}

int	validate_base(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		if (base[i] == '+' || base[i] == '-')
			return (0);
		while (base[j] != '\0')
		{
			if (base[i] == base[j])
			{
				return (0);
			}
			j++;
		}
		i++;
	}
	if (i < 2)
	{
		return (0);
	}
	return (1);
}

char	*ft_putnbr_base(int nbr, char *base)
{
	int		is_valid;
	char	*result;

	is_valid = validate_base(base);
	if (!is_valid)
	{
		return (NULL);
	}
	if (nbr == 0)
	{
		result = malloc(sizeof(char));
		if (!result)
			return (NULL);
		result[0] = base[0];
		return (result);
	}
	return (calc_base(nbr, base, find_the_base(base)));
}

// int	main(void)
// {
// 	int number = -2147483647 ;
// 	char	*base = "01";

// 	ft_putnbr_base(number, base);
// }
