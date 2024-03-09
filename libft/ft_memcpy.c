/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:19:20 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/07 12:55:36 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*result;
	const unsigned char	*source;

	if (!dst && !src)
		return (dst);
	i = 0;
	result = (unsigned char *)dst;
	source = (unsigned char *)src;
	while (i < n)
	{
		result[i] = source[i];
		i++;
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	const char src[50] = "https://www.tutorialspoint.com";
// 	char dest[50];
// 	strcpy(dest,"Heloooo!!");
// 	printf("Before memcpy dest = %s\n", dest);
// 	memcpy(dest, src, strlen(src)+1);
// 	printf("After memcpy dest = %s\n", dest);

// 	strcpy(dest,"Heloooo!!");
// 	printf("Before ft_memcpy dest = %s\n", dest);
// 	ft_memcpy(dest, src, strlen(src)+1);
// 	printf("After ft_memcpy dest = %s\n", dest);
// }
