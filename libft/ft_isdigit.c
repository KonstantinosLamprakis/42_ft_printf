/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:39:26 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 09:42:20 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int c = 1;
// 	printf("%d\n", ft_isdigit(c));
// 	printf("%d\n", isdigit(c));
// }
