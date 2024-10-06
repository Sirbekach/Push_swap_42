/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 11:59:52 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/14 12:44:40 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_list **lst)
{
	int		tmp;

	if (*lst == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst)->content;
	(*lst)->content = (*lst)->next->content;
	(*lst)->next->content = tmp;
}

void	ft_swap_a(t_list **a)
{
	if (a == NULL)
		return ;
	ft_swap(a);
	ft_printf("sa\n");
}

void	ft_swap_b(t_list **b)
{
	if (b == NULL)
		return ;
	ft_swap(b);
	ft_printf("sb\n");
}

void	ft_swap_ab(t_list **a, t_list **b)
{
	if (b == NULL || a == NULL)
		return ;
	ft_swap(a);
	ft_swap(b);
	ft_printf("ss\n");
}
