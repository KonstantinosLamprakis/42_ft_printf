/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 11:39:31 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/07 12:53:20 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t				i;
	unsigned char		*result;
	const unsigned char	*source;

	if (!dst && !src)
		return (dst);
	i = 0;
	result = (unsigned char *)dst;
	source = (unsigned char *)src;
	if (source < result)
	{
		i++;
		while (i <= len)
		{
			result[len - i] = source[len - i];
			i++;
		}
	}
	else
	{
		while (i++ < len)
			result[i - 1] = source[i - 1];
	}
	return (dst);
}

// #include <stdio.h>
// #include <string.h>
// int main(void)
// {
// 	char message2[60] = "abcdefghijklmnopqrstuvwxyz";
// 	char temp[60];
// 	strcpy(temp, message2);
// 	printf("Original message: %s\n", temp);
// 	memmove(temp + 4, temp + 16, 10);
// 	printf("After memmove() without overlap: %s\n", temp);
// 	strcpy(temp, message2);
// 	memmove(temp + 6, temp + 4, 10);
// 	printf("After memmove() with overlap: %s\n", temp);

// 	strcpy(temp, message2);
// 	ft_memmove(temp + 4, temp + 16, 10);
// 	printf("After ft_memmove() without overlap: %s\n", temp);
// 	strcpy(temp, message2);
// 	ft_memmove(temp + 6, temp + 4, 10);
// 	printf("After ft_memmove() with overlap: %s\n", temp);
// }
