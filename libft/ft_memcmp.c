/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:49:13 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 13:07:20 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char str1[15];
// 	char str2[15];
// 	int ret;
// 	int i = 1;

// 	memcpy(str1, "Abcdef", 6);
// 	memcpy(str2, "ABCDEF", 6);
// 	ret = memcmp(str1, str2, i);
// 	if(ret > 0)
// 		printf("str1 > str2\n");
// 	else if(ret < 0)
// 		printf("str1 < str2\n");
// 	else
// 		printf("str1 = str2\n");

// 	ret = ft_memcmp(str1, str2, i);
// 	if(ret > 0)
// 		printf("str1 > str2\n");
// 	else if(ret < 0)
// 		printf("str1 < str2\n");
// 	else
// 		printf("str1 = str2\n");
// }
