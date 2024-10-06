/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/12 16:17:53 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/15 10:39:26 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*list_to_array(t_list *lst)
{
	int		*tab;
	int		size;
	int		i;

	i = 0;
	size = list_size(lst);
	tab = malloc(sizeof(int) * (size));
	if (tab == NULL)
		return (NULL); 
	while (lst)
	{
		tab[i] = lst->content;
		lst = lst->next;
		i++;
	}
	return (tab);
}

int	*ft_bubble_sort(t_list *lst)
{
	int		*tab;
	int		i;
	int		size;
	int		j;

	i = 0;
	tab = list_to_array(lst);
	size = list_size(lst);
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
				swap_number(&tab[i], &tab[j]);
			j++;
		}
		i++;
	}
	return (tab);
}

void	indexing(t_list **lst)
{
	int		j;
	int		*tab;
	int		size;
	t_list	*temp;

	size = list_size((*lst));
	tab = ft_bubble_sort((*lst));
	j = 0;
	temp = *lst;
	while (temp)
	{
		j = 0;
		while (j < size)
		{
			if (temp->content == tab[j])
			{
				temp->index = j;
				break ;
			}
			j++;
		}
		temp = temp->next;
	}
	free(tab);
}

void	push_back(t_list **a, t_list **b)
{
	t_list	*big;

	while ((*b) != NULL)
	{
		big = max_list(*b);
		while ((*b)->content != big->content)
		{
			add_index(*b);
			if (big->index < (list_size(*b) / 2))
				rotate_b(b);
			else
				rrotate_b(b);
		}
		ft_push_a(b, a);
	}
}

void	sort_more(t_list **a, int range)
{
	t_list	*b;
	int		start;
	int		end;

	b = NULL;
	start = 0;
	indexing(a);
	while (*a)
	{
		end = start + range;
		if ((*a)->index < start)
		{
			ft_push_b(a, &b);
			rotate_b(&b);
			start++;
		}
		else if ((*a)->index >= start && (*a)->index <= end)
		{
			ft_push_b(a, &b);
			start++;
		}
		else
			rotate_a(a);
	}
	push_back(a, &b);
}
