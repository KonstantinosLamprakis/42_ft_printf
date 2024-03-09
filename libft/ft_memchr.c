/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 12:32:45 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 13:09:02 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	const unsigned char	*temp;

	temp = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		if (temp[i] == ((unsigned char) c))
			return ((void *)(&s[i]));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	const char *str = "Hello, World!";
// 	char sch = '\0';
// 	char *result = ft_memchr(str, sch, 25);
// 	if (result)
// 		printf("Character '%c' found at position %ld\n", sch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", sch);
// }
