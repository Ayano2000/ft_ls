/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_files_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:10:06 by ayano             #+#    #+#             */
/*   Updated: 2019/08/21 16:10:07 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files		*order_files_l(t_files **files)
{
	t_files			*current;
	t_files			*head;

	current = (*files);
	head = current;
	while (current->next != NULL)
	{
		if (current->name[0] == '.')
		{
			if (current->prev != NULL)
				current->next->prev = current->prev;
			free(current->name);
			free(current);
		}
		else if (current->name[0] > current->next->name[0])
			file_swap(&current, &current->next);
	}

}

void		file_swap(t_files **first, t_files **second)
{
	if (first && second)
	{
		if ((*second)->next)
			(*first)->next = (*second)->next;
		else
			(*first)->next = NULL;
		(*first)->prev = second;
		if ((*first)->prev)
			(*second)->prev = ((*first)->prev);
		else
			(*second)->prev = NULL;
		(*second)->next = first;
	}
}