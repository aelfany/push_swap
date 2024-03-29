/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_best_mv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abelfany <abelfany@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/24 19:01:28 by abelfany          #+#    #+#             */
/*   Updated: 2022/12/30 15:47:32 by abelfany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_save(t_nvr **root, int *item, int mark, int elem)
{
	t_nvr	*temp;
	t_nvr	*ptr;

	temp = malloc(sizeof(t_nvr));
	temp -> mov_a = item[0];
	temp -> mov_b = item[1];
	temp -> mark = mark;
	temp -> stack = elem;
	temp -> next = NULL;
	if (*root == NULL)
		*root = temp;
	else
	{
		ptr = *root;
		while (ptr-> next != NULL)
			ptr = ptr->next;
		ptr -> next = temp;
	}
}

int	go_pro(t_nvr *go)
{
	int	a;

	if (go-> mark == 0 || go-> mark == 2)
	{
		if (go -> mov_a < go -> mov_b)
			a = go -> mov_b;
		else
			a = go -> mov_a;
	}
	if (go -> mark == 1)
		a = go -> mov_a + go -> mov_b;
	return (a);
}

t_nvr	*find_best_mov(t_nvr *all)
{
	t_nvr	*head;
	t_nvr	*save;

	head = all-> next;
	save = NULL;
	if (all -> next == NULL)
		return (save = all);
	save = all;
	while (head)
	{
		if (go_pro(head) < go_pro(all))
		{
			save = head;
			all = head;
		}
		head = head -> next;
	}
	return (save);
}

void	check_a(t_nvr **sta, int kk, char c)
{
	int	jbl;

	jbl = hi(*sta, kk);
	while (1)
	{
		if ((*sta)-> stack == kk)
			break ;
		if (jbl == 1)
			rotate_a_b(&*sta, c);
		if (jbl == 0)
			reverse_rotate_a_b(&*sta, c);
	}
}
