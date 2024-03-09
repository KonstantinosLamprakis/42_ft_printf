/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 16:53:42 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/08 15:11:03 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	get_int(const char *str, int i, int sign);

int	ft_atoi(const char *str)
{
	int	i;
	int	t;
	int	sign;

	i = 0;
	t = 1;
	sign = 1;
	while (str[i] != '\0')
	{
		t = (str[i] != ' ') && (str[i] != '\n') && (str[i] != '\f');
		t = t && (str[i] != '\v') && (str[i] != '\t') && (str[i] != '\r');
		if (t)
			break ;
		i++;
	}
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	return (get_int(str, i, sign));
}

static int	get_int(const char *str, int i, int sign)
{
	int	div;
	int	result;
	int	end;

	result = 0;
	end = i;
	while (str[end] != '\0' && str[end] >= '0' && str[end] <= '9')
		end++;
	div = 1;
	if (end == 0)
		return (0);
	while (str[end - 1] >= '0' && str[end - 1] <= '9')
	{
		result = result - ((str[end - 1] - '0') * div);
		div *= 10;
		if (end == 1)
			break ;
		end--;
	}
	return (result * sign * -1);
}

// #include <stdio.h>
// #include <stdlib.h>
// int	main(void)
// {
// 	int		val;
// 	char	*str = "";
// 	// val = ft_atoi(str);
// 	val = ft_atoi(str);
// 	printf("\n->String value = %s, Int value = %d\n", str, val);
// }
