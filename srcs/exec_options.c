/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 16:54:35 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 09:34:15 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	exec_options(t_options **options)
{
	t_files		*files;

	files = init_files();
	files = get_files(&files);
	if ((*options)->l == 1)
		// TODO -l -a -t -r -R.
	return ;
}

t_files	*init_files(void)
{
	t_files		*files;

	files = (t_files *)malloc(sizeof(t_files));
	files->head = NULL;
	files->name = NULL;
	files->next = NULL;
	files->prev = NULL;
	files->time = 0;
	return(files);	
}