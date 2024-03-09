/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:12:54 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 10:16:05 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int c = '\0';
// 	printf("%d\n", ft_isascii(c));
// 	printf("%d\n", isascii(c));
// }
