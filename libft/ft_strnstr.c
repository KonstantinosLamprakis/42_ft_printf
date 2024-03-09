/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 13:10:07 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/07 14:55:57 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	if (needle[0] == '\0')
		return ((char *)haystack);
	i = 0;
	while (haystack[i] != '\0')
	{
		j = 0;
		while (i + j < len && haystack[i + j] == needle[j]
			&& haystack[i + j] != '\0' && needle[j] != '\0')
			j++;
		if (needle[j] == '\0')
			return ((char *)(haystack + i));
		i++;
	}
	return (NULL);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*str = "Be the best version dude!";
// 	char	*to_find = "  ";
// 	char	*result;
// 	int		i = 10;

// 	result = strnstr(str, to_find, i);
// 	printf("%s\n", result);
// 	result = ft_strnstr(str, to_find, i);
// 	printf("%s", result);
// }
