/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 17:10:44 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 08:58:20 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"


t_files		*exec_l_flag(t_files **files)
{
	DIR				*dir;
	struct dirent	*file;
	dir = opendir(".");
	if (dir == NULL)
	{
		ft_putstr("Unable to open the current directory");
		exit(1);
	}
	while ((file = readdir) != NULL)
	{
		(*files)->name = ft_strdup(&file->d_name);
		add_node(files);
	}
}