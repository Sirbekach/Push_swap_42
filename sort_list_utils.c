/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_list_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 12:02:43 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/15 11:28:27 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*small_list(t_list *lst)
{
	t_list	*small;

	small = lst;
	while (lst)
	{
		if (small->content > lst->content)
			small = lst;
		lst = lst->next;
	}
	return (small);
}

t_list	*max_list(t_list *lst)
{
	t_list	*big;

	big = lst;
	while (lst)
	{
		if (big->content < lst->content)
			big = lst;
		lst = lst->next;
	}
	return (big);
}

void	add_index(t_list *lst)
{
	int		i;

	i = 0;
	while (lst)
	{
		lst->index = i;
		lst = lst->next;
		i++;
	}
}

int	is_sorted(t_list *lst)
{
	while (lst->next != NULL)
	{
		if (lst->content > lst->next->content)
			return (0);
		lst = lst->next;
	}
	return (1);
}
