/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 08:46:37 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 08:22:16 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** adds a node to the end of the list.
*/
t_files		*add_node(t_files **head)
{
	t_files		*new;
	t_files		*current;

	current = (*head);
	new = init_files();
	while (current->next != NULL)
		current = current->next;
	if (current && new)
	{
		current->next = new;
		new->next = NULL;
		new->prev = current;
	}
	return (*head);
}