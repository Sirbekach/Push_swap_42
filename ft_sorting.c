/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/07 11:36:53 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/15 11:42:18 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_list **lst)
{
	if ((*lst)->content > (*lst)->next->content)
		ft_swap_a(lst);
}

void	sort_three(t_list **lst)
{
	t_list	*tmp;
	int		first;
	int		second;
	int		third;

	tmp = *lst;
	first = tmp->content;
	second = tmp->next->content;
	third = tmp->next->next->content;
	if (first > second && first < third)
		ft_swap_a(lst);
	else if (first > second && second > third)
	{
		ft_swap_a(lst);
		rrotate_a(lst);
	}
	else if (first > third && second < third)
		rotate_a(lst);
	else if (second > third && third > first)
	{
		ft_swap_a(lst);
		rotate_a(lst);
	}
	else if (second > first && first > third)
		rrotate_a(lst);
}

static void	sort_two_three(t_list **lst)
{
	if (list_size(*lst) == 2)
		sort_two(lst);
	else if (list_size(*lst) == 3)
		sort_three(lst);
}

void	sort_five(t_list **a)
{
	t_list	*b;
	t_list	*last;
	int		small;
	int		i;

	b = NULL;
	i = 0;
	while (i < 2)
	{
		last = last_list(*a);
		small = small_list(*a)->content;
		if (last->content == small)
			rrotate_a(a);
		else
		{
			while ((*a)->content != small)
				rotate_a(a);
		}
		ft_push_b(a, &b);
		i++;
	}
	sort_two_three(a);
	while (b)
		ft_push_a(&b, a);
}
