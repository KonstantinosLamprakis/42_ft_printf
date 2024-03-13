/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 19:19:56 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 17:30:34 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*print_u(va_list par_list, const char *format, int index)
{
	int		ch_num;
	char	*result;
	int		nbr;
	char	*temp;
	int		f_width;

	is_fstop(format, index, &f_width, par_list);
	nbr = va_arg(par_list, int);
	ch_num = (count_digits(nbr, 10));
	result = malloc((count_digits(nbr, 10) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	get_hex(nbr, 10, result, 1);
	str_revert(result);
	if (!(is_plus_f(format, index) || is_space_f(format, index)))
		return (get_percision(f_width, result));
	temp = get_percision(f_width, result);
	if (!temp)
		return (NULL);
	if (is_plus_f(format, index))
		result = ft_strjoin("+", temp);
	else
		result = ft_strjoin(" ", temp);
	free(temp);
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

char	*print_x(va_list par_list, char c, int is_hash)
{
	int		ch_num;
	char	*result;
	int		nbr;
	char	*temp;

	nbr = va_arg(par_list, ssize_t);
	ch_num = (count_digits(nbr, 16));
	temp = malloc((count_digits(nbr, 16) + 1) * sizeof(char));
	if (!temp)
		return (NULL);
	if (c == 'x')
		get_hex(nbr, 0, temp, 1);
	else
		get_hex(nbr, 1, temp, 1);
	str_revert(temp);
	if (!is_hash)
		return (temp);
	if (c == 'x')
		result = ft_strjoin("0x", temp);
	else
		result = ft_strjoin("0X", temp);
	free(temp);
	return (result);
}
