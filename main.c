/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/02 12:42:33 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/15 13:15:35 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_algo(t_list *num)
{
	int		size;

	size = list_size(num);
	if (size == 2)
		sort_two(&num);
	else if (size == 3)
		sort_three(&num);
	else if (size == 5 || size == 4)
		sort_five(&num);
	else if (size > 5 || size <= 100)
		sort_more(&num, 15);
	else if (size > 100)
		sort_more(&num, 30);
	free_list(&num);
}

int	main(int argc, char **argv)
{
	t_list	*num;

	num = read_arg(argc, argv);
	if (!num)
	{
		write(2, "Error\n", 6);
		return (0);
	}
	if (is_sorted(num))
	{
		free_list(&num);
		return (0);
	}
	if (list_size(num) == 1)
	{
		free_list(&num);
		return (0);
	}
	sort_algo(num);
	return (0);
}
