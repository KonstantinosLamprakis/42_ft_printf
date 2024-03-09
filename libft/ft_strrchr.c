/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 11:50:26 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 12:38:03 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*result;

	i = 0;
	result = NULL;
	while (s[i] != '\0')
	{
		if (s[i] == ((char) c))
			result = ((char *)(&s[i]));
		i++;
	}
	if (((char) c) == s[i])
		result = ((char *)(&s[i]));
	return (result);
}

// #include <stdio.h>
// #include <string.h>
// int main() {
// 	const char *str = "Hello, World!";
// 	char sch = 'o';
// 	char *result = ft_strrchr(str, sch);
// 	if (result)
// 		printf("Character '%c' found at position %ld\n", sch, result - str);
// 	else
// 		printf("Character '%c' not found in the string.\n", sch);
// }
