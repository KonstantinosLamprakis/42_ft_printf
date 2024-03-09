/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 10:35:37 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/08 10:55:13 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*i;

	if (!new)
		return ;
	if (lst)
	{
		i = *lst;
		if (*lst)
		{
			while (i->next)
				i = i->next;
			i->next = new;
		}
		else
			*lst = new;
	}
	else
		lst = &new;
}
