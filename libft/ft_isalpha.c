/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 09:24:50 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 09:37:45 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

// #include <stdio.h>
// #include <ctype.h>
// int	main(void)
// {
// 	int c = '\0';
// 	printf("%d\n", ft_isalpha(c));
// 	printf("%d\n", isalpha(c));
// }
