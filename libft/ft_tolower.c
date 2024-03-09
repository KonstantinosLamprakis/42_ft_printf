/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:18:56 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 11:25:16 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 'a' - 'A';
	return (c);
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int a;
// 	int c = '~';

// 	a = c;
// 	printf("%d\n", ft_tolower(a));
// 	a = c;
// 	printf("%d\n", tolower(a));
// }
