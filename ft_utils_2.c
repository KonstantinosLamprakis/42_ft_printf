/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:19:56 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 19:22:21 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_u(va_list par_list)
{
	int		ch_num;
	char	*result;
	int		nbr;

	nbr = va_arg(par_list, int);
	ch_num = (count_digits(nbr, 10));
	result = malloc((count_digits(nbr, 10) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	get_hex(nbr, 10, result, 1);
	str_revert(result);
	return (result);
}

char	*print_ptr(va_list par_list)
{
	int					ch_num;
	char				*result;
	void				*ptr_nbr;
	char				*temp;
	unsigned long long	nbr;

	ptr_nbr = va_arg(par_list, void *);
	if (ptr_nbr == NULL)
		return (ft_strdup("0x0"));
	nbr = (unsigned long long) ptr_nbr;
	ch_num = (count_digits(nbr, 16));
	temp = malloc((count_digits(nbr, 16) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	get_hex(nbr, 0, temp, 0);
	str_revert(temp);
	result = ft_strjoin("0x", temp);
	free(temp);
	return (result);
}

char	*print_x(va_list par_list, char c)
{
	int		ch_num;
	char	*result;
	int		nbr;

	nbr = va_arg(par_list, ssize_t);
	ch_num = (count_digits(nbr, 16));
	result = malloc((count_digits(nbr, 16) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (c == 'x')
		get_hex(nbr, 0, result, 1);
	else
		get_hex(nbr, 1, result, 1);
	str_revert(result);
	return (result);
}
