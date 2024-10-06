/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 09:57:49 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/14 12:44:14 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **lst)
{
	t_list	*head;
	t_list	*tail;

	if (list_size(*lst) < 2)
		return ;
	tail = last_list(*lst);
	head = *lst;
	*lst = (*lst)->next;
	head->next = NULL;
	tail->next = head;
}

void	rotate_a(t_list **a)
{
	if (list_size(*a) < 2)
		return ;
	rotate(a);
	ft_printf("ra\n");
}

void	rotate_b(t_list **b)
{
	if (list_size(*b) < 2)
		return ;
	rotate(b);
	ft_printf("rb\n");
}

void	rotate_ab(t_list **a, t_list **b)
{
	if (list_size(*a) < 2 || list_size(*b) < 2)
		return ;
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
