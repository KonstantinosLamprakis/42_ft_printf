/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 10:54:02 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 11:04:27 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	temp;
	unsigned int	src_n;
	unsigned int	dest_n;

	dest_n = (unsigned int)ft_strlen(dst);
	src_n = (unsigned int)ft_strlen(src);
	temp = dest_n;
	if (dstsize <= dest_n)
	{
		return ((size_t)(src_n + dstsize));
	}
	while (*src && temp < dstsize - 1)
	{
		dst[temp] = *src;
		src++;
		temp++;
	}
	if (temp < dstsize)
	{
		dst[temp] = '\0';
	}
	return ((size_t)(src_n + dest_n));
}

// #include <string.h>
// #include <stdio.h>
// #include <stdlib.h>
// int	main()
// {
// 	char	dst[20] = "Hello ";
// 	char	*src = "World";
// 	int		size = 17;
// 	size_t len = ft_strlcat(dst, src, size);
// 	//size_t len = strlcat(dst, src, size);
// 	printf("Expected string: %s\n", dst);
// 	printf("Expected return value: %zu\n", len);
// 	return 0;
// }
