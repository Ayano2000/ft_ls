/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_R_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 09:31:03 by ayano             #+#    #+#             */
/*   Updated: 2019/08/23 12:34:54 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void        exec_R_flag(void)
{
    t_files		*files;
    t_files		*current;
    struct stat	dir_or_not;
	int			max_len;
	int			i;

	files = init_files();
    files = get_files(&files);
	ft_putstr("HERE1\n");
	max_len = longest_name(&files);
	current = files;
	i = 0;
    while (current->next)
	{
		if (current->name[0] == '.')
			current = current->next;
		if (stat(current->name, &dir_or_not) == 0)
		{
			if (ft_strlen(current->name) < max_len)
			{
				if (current->prev == NULL)
				{
					i = ft_strlen(current->name);
					ft_putstr(current->name);
					while (i < max_len)
					{
						ft_putstr(" ");
						i++;
					}
				}
			}
			if (dir_or_not.st_mode & S_IFDIR)
			{
				if (ft_strlen(current->name) < max_len)
				{
					if (current->prev == NULL)
					{
						i = ft_strlen(current->name);
						ft_putstr(current->name);
						while (i < max_len)
						{
							ft_putstr(" ");
							i++;
						}
					}
				}
				current->head = get_files_in_dir(current->name);
			}
		}
		current = current->next;
	}
	exit(1);
}

t_files		*get_files_in_dir(char *name)
{
	DIR				*dir;
	t_files			*current;
	struct dirent	*file;

	dir = opendir(name);
	while ((file = readdir(dir)) != NULL)
	{
		current->name = ft_strdup(file->d_name);
		add_node(&current);
		while (current->next != NULL)
			current = current->next;
	}
}