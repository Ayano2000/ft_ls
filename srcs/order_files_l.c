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
			current->next->prev = current->prev;
			head = current->next;
			free(current->name);
			free(current);
		}
	}
}