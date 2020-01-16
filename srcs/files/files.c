/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:20:12 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 13:20:15 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

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
        printf("%s\n", file->d_name);
		// current->name = ft_strdup(file- >d_name);
		// add_node(&current);
		// while (current->next != NULL)
		// 	current = current->next;
	}
	return (*files);
}
