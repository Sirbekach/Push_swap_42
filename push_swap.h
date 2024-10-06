/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybekach <ybekach@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 10:31:14 by ybekach           #+#    #+#             */
/*   Updated: 2024/09/15 11:27:01 by ybekach          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"

typedef struct list
{
	int			content;
	int			index;
	struct list	*next;
}				t_list;

t_list		*new_list(int value);
void		rotate(t_list **lst);
void		rotate_a(t_list **a);
void		rotate_b(t_list **b);
void		ft_swap(t_list **lst);
void		ft_swap_a(t_list **a);
void		ft_swap_b(t_list **b);
void		rrotate(t_list **lst);
void		rrotate_a(t_list **a);
void		rrotate_b(t_list **b);
void		sort_five(t_list **a);
int			is_sorted(t_list *lst);
int			list_size(t_list *lst);
void		sort_two(t_list **lst);
void		add_index(t_list *lst);
t_list		*max_list(t_list *lst);
void		free_list(t_list **lst);
t_list		*last_list(t_list *lst);
t_list		*small_list(t_list *lst);
void		sort_three(t_list **lst);
void		free_matrix(char **matrix);
void		swap_number(int *a, int *b);
t_list		*read_num(t_list *lst, char *s);
t_list		*read_arg(int argc, char **argv);
void		sort_more(t_list **a, int range);
void		rotate_ab(t_list **a, t_list **b);
int			check_num(t_list *lst, char *word);
void		fill_list(t_list **lst, int value);
void		rrotate_ab(t_list **a, t_list **b);
void		ft_swap_ab(t_list **a, t_list **b);
void		ft_push(t_list **lst, t_list **new);
void		ft_push_a(t_list **a, t_list **new);
void		ft_push_b(t_list **b, t_list **new);

#endif