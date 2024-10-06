/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arguments.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 12:37:38 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/14 16:04:38 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_list(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
}

t_list	*read_num(t_list *lst, char *s)
{
	int		i;
	int		n;
	char	**word;
	t_list	*num;

	if (s == NULL)
		return (NULL);
	i = 0;
	num = NULL;
	word = ft_split(s, 32);
	if (word == NULL)
		return (NULL);
	while (word[i])
	{
		if (!check_num(num, word[i]) || !check_num(lst, word[i]))
			return (free_matrix(word), NULL);
		n = ft_atoi(word[i]);
		fill_list(&num, n);
		if (num == NULL)
			return (free_matrix(word), NULL);
		i++;
	}
	free_matrix(word);
	return (num);
}

t_list	*read_arg(int argc, char **argv)
{
	t_list	*num;
	t_list	*current;
	t_list	*temp;
	int		i;

	num = NULL;
	i = 1;
	while (i < argc)
	{
		temp = read_num(num, argv[i]);
		if (temp == NULL)
			return (free(num), free(temp), NULL);
		if (num == NULL)
			num = temp;
		else
		{
			current = num;
			while (current->next != NULL)
				current = current->next;
			current->next = temp;
		}
		i++;
	}
	return (num);
}
