/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: klamprak <klamprak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 11:03:27 by klamprak          #+#    #+#             */
/*   Updated: 2024/03/08 12:20:04 by klamprak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*i;
	t_list	*prev;

	if (!lst)
		return ;
	if (!(*lst))
	{
		lst = NULL;
		return ;
	}
	i = *lst;
	(*del)(i->content);
	while ((i->next))
	{
		prev = i;
		i = i->next;
		free(prev);
		prev = NULL;
		(*del)(i->content);
	}
	if (i)
		free(i);
	*lst = NULL;
}
