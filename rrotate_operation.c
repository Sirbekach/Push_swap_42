/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate_operation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/06 12:22:40 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/07 15:32:04 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rrotate(t_list **lst)
{
	t_list	*pre;
	t_list	*tail;
	int		i;

	i = 0;
	if (list_size(*lst) < 2)
		return ;
	tail = *lst;
	while (tail->next != NULL)
	{
		pre = tail;
		tail = tail->next;
	}
	pre->next = NULL;
	tail->next = *lst;
	*lst = tail;
}

void	rrotate_a(t_list **a)
{
	if (list_size(*a) < 2)
		return ;
	rrotate(a);
	ft_printf("rra\n");
}

void	rrotate_b(t_list **b)
{
	if (list_size(*b) < 2)
		return ;
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrotate_ab(t_list **a, t_list **b)
{
	if (list_size(*b) < 2)
		return ;
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
