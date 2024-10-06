/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/22 11:53:31 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/15 12:52:58 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

void	free_matrix(char **matrix)
{
	int		i;

	if (matrix == NULL)
		return ;
	i = 0;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	swap_number(int *a, int *b)
{
	int		tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

long	convert_to_number(char *word, int *i, int sign)
{
	long	number; 

	number = 0;
	while (word[*i])
	{
		if (!ft_isdigit(word[*i]))
			return (2147483648);
		number = number * 10 + (word[*i] - '0');
		if (number * sign > INT_MAX || number * sign < INT_MIN)
			return (2147483648);
		(*i)++;
	}
	return (number * sign);
}

int	check_duplicate(t_list *lst, long number)
{
	t_list	*temp;

	temp = lst;
	while (temp)
	{
		if (temp->content == number)
			return (0);
		temp = temp->next;
	}
	return (1);
}

int	check_num(t_list *lst, char *word)
{
	int		i;
	int		sign;
	long	number;

	i = 0;
	sign = 1;
	if ((word[i] == '-' || word[i] == '+') && word[i + 1] != '\0' )
	{
		sign = 1 - 2 * (word[i] == '-');
		i++;
	}
	number = convert_to_number(word, &i, sign);
	if (number == 2147483648)
		return (0);
	return (check_duplicate(lst, number));
}
