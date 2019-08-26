/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:54:35 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 08:48:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** Will call correct functions based on the flags given.
*/
void	exec_options(t_options **options)
{
	t_files		*files;

	files = init_files();
	files = get_files(&files);
	get_permissions(&files);
	while (files->next != NULL)
	{
		printf("%s\n", files->name);
		files = files->next;
	}
	return ;
}

/*
** initialize the flags struct.
*/
t_files	*init_files(void)
{
	t_files		*files;

	files = (t_files *)malloc(sizeof(t_files));
	files->name = NULL;
	files->next = NULL;
	files->prev = NULL;
	files->perm = ft_strnew(11);
	files->is_dir = 0;
	files->time = 0;
	return(files);	
}