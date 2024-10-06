/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 12:39:12 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/06 09:53:36 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push(t_list **lst, t_list **new)
{
	t_list	*tmp;

	if (*lst == NULL)
		return ;
	tmp = *lst;
	*lst = (*lst)->next;
	tmp->next = *new;
	*new = tmp;
}

void	ft_push_a(t_list **a, t_list **new)
{
	if (*a == NULL)
		return ;
	ft_push(a, new);
	ft_printf("pa\n");
}

void	ft_push_b(t_list **b, t_list **new)
{
	if (*b == NULL)
		return ;
	ft_push(b, new);
	ft_printf("pb\n");
}
