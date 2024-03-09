/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:17:19 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 10:20:19 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	return (c >= 32 && c <= 126);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int c = '	';
// 	printf("%d\n", ft_isprint(c));
// 	printf("%d\n", isprint(c));
// }
