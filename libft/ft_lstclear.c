/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yoishi <yoishi@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 21:16:05 by yoishi            #+#    #+#             */
/*   Updated: 2024/04/22 00:05:59 by yoishi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next;

	if (!lst || !(*lst) || !del)
		return ;
	while ((*lst))
	{
		next = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = next;
	}
	if (!lst)
		free(lst);
}

// saigo no youso wo lst ni ireru koto de, clear;
