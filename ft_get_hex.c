/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:41:39 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/12 18:04:53 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	count_digits(t_u_long num);
static void	get_hex(t_u_long nbr, int upper_case, char *result, int is_int);
static void	str_revert(char *str);

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
	ch_num = (count_digits(nbr));
	temp = malloc((count_digits(nbr) + 1) * sizeof(char));
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
	ch_num = (count_digits(nbr));
	result = malloc((count_digits(nbr) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	if (c == 'x')
		get_hex(nbr, 0, result, 1);
	else
		get_hex(nbr, 1, result, 1);
	str_revert(result);
	return (result);
}

static void	str_revert(char *str)
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

static void	get_hex(t_u_long nbr, int is_up_case, char *result, int is_int)
{
	static char	up_dig[] = "0123456789ABCDEF";
	static char	lo_dig[] = "0123456789abcdef";

	if (is_int)
		nbr = (unsigned int) nbr;
	if (nbr >= 16)
		get_hex((nbr / 16), is_up_case, result + 1, is_int);
	else
		result[1] = '\0';
	if (is_up_case)
		*result = up_dig[nbr % 16];
	else
		*result = lo_dig[nbr % 16];
}

static int	count_digits(unsigned long long num)
{
	int	result;

	result = 0;
	if (num == 0)
		return (1);
	while (num != 0)
	{
		result += 1;
		num /= 16;
	}
	return (result);
}
