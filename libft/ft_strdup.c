/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:04:54 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/06 17:39:04 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char	*dest, const char	*src);

char	*ft_strdup(const char	*s1)
{
	char	*dst;

	dst = malloc(ft_strlen(s1) + 1);
	if (!dst)
		return (dst);
	ft_strcpy(dst, s1);
	return (dst);
}

static char	*ft_strcpy(char	*dest, const char	*src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char source[] = "42 Heilbron";
// 	char *target = ft_strdup(source);
// 	printf("%s", target);
// 	return 0;
// }
