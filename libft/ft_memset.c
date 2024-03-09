/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:33:45 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 10:56:07 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			i;
	unsigned char	*result;

	i = 0;
	result = (unsigned char *)b;
	while (i < len)
	{
		result[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	str[50];
// 	strcpy(str, "This is string.h library function");
// 	puts(str);
// 	memset(str, '$', 7);
// 	puts(str);
// 	ft_memset(str, '1', 8);
// 	puts(str);
// }
