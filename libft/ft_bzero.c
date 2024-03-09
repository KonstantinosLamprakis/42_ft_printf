/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 10:55:53 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/05 11:10:38 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	if (n != 0)
		ft_memset(s, 0, n);
}

// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	str[50];
// 	int		i;

// 	strcpy(str, "This is string.h library function");
// 	puts(str);
// 	i = 0;
// 	bzero(str, 7);
// 	while(str[i] == '\0' && str[i + 1] == '\0')
// 		i++;
// 	printf("zeros from bzero: %d\n", i);
// 	strcpy(str, "This is string.h library function");
// 	i = 0;
// 	ft_bzero(str, 7);
// 	while(str[i] == '\0' && str[i + 1] == '\0')
// 		i++;
// 	printf("zeros from bzero: %d\n", i);
// }
