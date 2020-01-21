/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   subdir.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/21 21:46:43 by ayano             #+#    #+#             */
/*   Updated: 2020/01/21 21:46:44 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files		*add_subdir(t_files **files)
{
	t_files *head;
	t_files *current;
	t_files *sub_files;;

	head = (*files);
	current = head;

	while (current) {
		if (current->permissions[0] == 'd')
		{
			sub_files = add_subdir_files(current->name);
		}
		current =current->next;
	}
	return (head);
}

t_files		*add_subdir_files(char *dir_name)
{
	t_files *new;
	DIR		*dir;
	// get_files does the loop to get them all.
	new = init_files();
	dir = opendir(dir_name);
	
}