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
	t_files *sub_files;
	t_files *cursor;


	head = (*files);
	current = head;

	while (current) {
		if (current->permissions[0] == 'd' && 
			ft_strequ(current->name, ".") != 1 &&
			ft_strequ(current->name, "..") != 1)
		{
			current->sub_files = add_subdir_files(current->name);
			output(&(current)->sub_files);
			// break ;
		}
		printf("\n\n");
		current =current->next;
	}
	return (head);
}

t_files		*add_subdir_files(char *dir_name)
{
	t_files *new;
	DIR		*dir;
	struct dirent *data;
	// get_files does the loop to get them all.
	new = init_files();
	new = get_files(&new, dir_name);
	new = init_subdir_data(&new);
	printf("%s\n", dir_name);
	return (new);
}

t_files     *init_subdir_data(t_files **files)
{
    (*files) = set_users(files);
    (*files) = set_groups(files);
    (*files) = set_size(files);
    (*files) = set_time(files);
    (*files) = set_permissions(files);
    (*files) = set_links(files);
    return (*files);
}