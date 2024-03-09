/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:22:43 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 10:29:10 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *s)
{
	size_t	counter;

	counter = 0;
	while (s[counter] != '\0')
		counter++;
	return (counter);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char *c = "";
// 	printf("%zd\n", ft_strlen(c));
// 	printf("%zd\n", strlen(c));
// }
