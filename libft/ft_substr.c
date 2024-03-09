/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:41:33 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/08 17:03:50 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*get_empty(void);

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*result;

	if ((int) len < 0)
		len = ft_strlen(s);
	if (start > ft_strlen(s) || len < 0)
		return (get_empty());
	if (ft_strlen(s) - start < len)
		result = malloc((ft_strlen(s) - start + 1) * sizeof(char));
	else
		result = malloc((len + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s[i + start] != '\0' && i < len)
	{
		result[i] = s[i + start];
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*get_empty(void)
{
	char	*result;

	result = malloc(1 * sizeof(char));
	if (!result)
		return (NULL);
	result[0] = '\0';
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	// char const *s = "This is a test";
// 	// char *result = ft_substr(s, 5, 1);
// 	// char *result = ft_substr("hola", 0, 42949672951);
// 	char *result = ft_substr("hola", 0, 18446744073709551615);
// 	puts(result);
// }
