/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:43:16 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 09:58:01 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	return (ft_isalpha(c) || ft_isdigit(c));
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int c = -1;
// 	printf("%d\n", ft_isalnum(c));
// 	printf("%d\n", isalnum(c));
// }
