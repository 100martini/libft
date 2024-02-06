/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wel-kass <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 06:51:22 by wel-kass          #+#    #+#             */
/*   Updated: 2023/11/18 06:52:02 by wel-kass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*holder;

	new = NULL;
	if (lst && f && del)
	{
		while (lst)
		{
			holder = ft_lstnew(f(lst->content));
			if (!holder)
			{
				ft_lstclear(&new, del);
				return (NULL);
			}
			ft_lstadd_back(&new, holder);
			lst = lst->next;
		}
		return (new);
	}
	return (NULL);
}
