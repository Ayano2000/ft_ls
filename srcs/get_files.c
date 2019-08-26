/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_files.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:10:44 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 08:46:10 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** will get all files in the current directory/
*/
t_files		*get_files(t_files **files)
{
	DIR				*dir;
	struct dirent	*file;
	t_files			*current;

	current = (*files);
	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putstr("Unable to open the current directory");
		exit(1);
	}
	while ((file = readdir(dir)) != NULL)
	{
		current->name = ft_strdup(file->d_name);
		add_node(&current);
		while (current->next != NULL)
			current = current->next;
	}
	return (*files);
}