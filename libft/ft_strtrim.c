/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 18:24:46 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/07 08:02:58 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_contained(char const *set, char c);

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	int		j;
	char	*result;

	start = 0;
	end = ft_strlen(s1) - 1;
	if (ft_strlen(s1) > 0)
	{
		while (is_contained(set, s1[start]))
			start++;
		while (is_contained(set, s1[end]))
			end--;
	}
	if (start > end)
		result = malloc(sizeof(char));
	else
		result = malloc((end - start + 2) * sizeof(char));
	if (!result)
		return (NULL);
	j = 0;
	while (start <= end)
		result[j++] = s1[start++];
	result[j] = '\0';
	return (result);
}

static int	is_contained(char const *set, char c)
{
	int	i;

	i = 0;
	while (set[i] != '\0')
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char const *s1 = "";
// 	char const *set = " a-";
// 	char *result = ft_strtrim(s1, set);
// 	puts(result);
// }
