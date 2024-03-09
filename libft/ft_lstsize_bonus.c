/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:02:48 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/08 10:05:09 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// TODO
int	ft_lstsize(t_list *lst)
{
	int	i;

	if (!lst)
		return (0);
	i = 1;
	while (lst->next)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}

// int main(void)
// {
// 	t_list * l =  NULL;
// 	ft_lstnew((void*)1);
// 	printf("size: %d\n", ft_lstsize(l));

// 	ft_lstadd_front(&l, ft_lstnew((void*)1));
// 	printf("size: %d\n", ft_lstsize(l));
// 	printf("");

// 	ft_lstadd_front(&l, ft_lstnew((void*)2));
// 	printf("size: %d\n", ft_lstsize(l));

// 	return (0);
// }
