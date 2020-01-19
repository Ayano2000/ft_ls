/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nodes.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:15:00 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 14:15:02 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *add_node(t_files **head)
{
	t_files     *new;
	t_files     *current;

	current = (*head);
	new = init_files();
	while (current->next != NULL)
		current = current->next;
	if (current && new)
	{
		current->next = new;
		new->previous = current;
		new->next = NULL;
	}
	return (*head);
}

t_files     *init_files(void)
{
    t_files     *file_node;

    file_node = (t_files *)malloc(sizeof(t_files) * 1);
    file_node->permissions = NULL;
    file_node->links = 0;
    file_node->user = NULL;
    file_node->group = NULL;
    file_node->size = NULL;
    file_node->time = NULL;
    file_node->name = NULL;
    file_node->next = NULL;
	file_node->previous = NULL;
    return(file_node);
}