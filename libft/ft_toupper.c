/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:05:23 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 11:26:23 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 'a' - 'A';
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int a;
// 	int c = 'A';

// 	a = c;
// 	printf("%c\n", ft_toupper(a));
// 	a = c;
// 	printf("%c\n", toupper(a));
// }
