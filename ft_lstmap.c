/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/03 20:41:28 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/03 20:41:28 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_list	*ft_lstnew_behind(t_list **tail, void *content,
					void (*del)(void *));

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*tail;

	head = NULL;
	tail = NULL;
	while (lst)
	{
		if (!ft_lstnew_behind(&tail, f(lst->content), del))
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		if (!head)
			head = tail;
		lst = lst->next;
	}
	return (head);
}

static t_list	*ft_lstnew_behind(t_list **tail, void *content,
		void (*del)(void *))
{
	t_list	*new;

	new = ft_lstnew(content);
	if (!new)
	{
		del(content);
		return (NULL);
	}
	if (*tail)
		(*tail)->next = new;
	*tail = new;
	return (new);
}
