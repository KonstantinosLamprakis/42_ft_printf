/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:07:59 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/07 07:26:32 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		i;
	int		j;

	result = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!result)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		result[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		result[j + i] = s2[j];
		j++;
	}
	result[i + j] = '\0';
	return (result);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char const *s1 = "This is";
// 	char const *s2 = "\n a test";
// 	char *result = ft_strjoin(s1, s2);
// 	puts(result);
// }
