/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:41:39 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 19:22:20 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	str_revert(char *str)
{
	char	*temp;
	int		i;
	int		j;

	temp = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!temp)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		temp[i] = str[i];
		i++;
	}
	i--;
	j = 0;
	while (i >= 0)
	{
		str[j++] = temp[i];
		i--;
	}
	free(temp);
}

void	get_hex(t_u_long nbr, int is_up_case, char *result, int is_int)
{
	static char	up_dig[] = "0123456789ABCDEF";
	static char	lo_dig[] = "0123456789abcdef";
	static char	dec_dig[] = "0123456789";
	t_u_long	base;

	base = 16;
	if (is_up_case == 10)
		base = 10;
	if (is_int)
		nbr = (unsigned int) nbr;
	if (nbr >= base)
		get_hex((nbr / base), is_up_case, result + 1, is_int);
	else
		result[1] = '\0';
	if (is_up_case == 1)
		*result = up_dig[nbr % base];
	else if (is_up_case == 10)
		*result = dec_dig[nbr % base];
	else
		*result = lo_dig[nbr % base];
}

int	count_digits(t_u_long num, int base)
{
	int	result;

	result = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		result += 1;
		num /= base;
	}
	return (result);
}
