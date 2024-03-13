/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 09:03:06 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/13 16:36:32 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*get_percision(int f_width, char *num);

// if is % just print it and return
char	*print_percent(void)
{
	char	*result;

	result = malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '%';
	result[1] = '\0';
	return (result);
}

char	*print_char(va_list par_list, int *is_null)
{
	char	*result;

	result = malloc(2 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = va_arg(par_list, int);
	result[1] = '\0';
	if (result[0] == '\0')
	{
		*is_null = -1;
		free(result);
		return (NULL);
	}
	return (result);
}

char	*print_str(va_list par_list, const char *format, int index)
{
	char	*result;
	int		f_width;
	int		is_full_stop;

	f_width = -1;
	is_full_stop = is_fstop(format, index, &f_width, par_list);
	if(f_width == 0)
		return (NULL);
	result = va_arg(par_list, char *);
	if (!result)
		return (ft_substr("(null)", 0, f_width));
	if (is_full_stop)
		return (ft_substr(result, 0, f_width));
	return (ft_strdup(result));
}

char	*print_i_d(va_list par_list, const char *format, int index)
{
	int		num;
	char	*result;
	char	*temp;
	int		f_width;

	is_fstop(format, index, &f_width, par_list);
	num = va_arg(par_list, int);
	if (num < 0 || !(is_plus_f(format, index) || is_space_f(format, index)))
		return (get_percision(f_width, ft_itoa(num)));
	temp = get_percision(f_width, ft_itoa(num));
	if (!temp)
		return (NULL);
	if (is_plus_f(format, index))
		result = ft_strjoin("+", temp);
	else
		result = ft_strjoin(" ", temp);
	free(temp);
	return (result);
}

char	*get_percision(int f_width, char *num)
{
	int		sign;
	int		i;
	char	*zeros;
	char	*result;

	if (!num)
		return (num);
	sign = num[0] == '-';
	i = f_width - (ft_strlen(num) - sign);
	if (i <= 0)
		return (num);
	zeros = malloc((i + 1 + sign) * sizeof(char));
	if (!zeros)
		return (NULL);
	if (sign)
		zeros[0] = '-';
	zeros[i + sign] = '\0';
	i += sign - 1;
	while (i >= sign)
		zeros[i--] = '0';
	result = ft_strjoin(zeros, num + sign);
	free(zeros);
	free(num);
	return (result);
}

// checks if c is included on str.
// If yes, return its position, otherwise return -1.
int	is_included(const char *str, char c)
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
