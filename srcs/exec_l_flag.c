/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:43:34 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 11:48:18 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files		*exec_l_flag(t_files **files)
{
	int		total;
	char	*permissions;
	t_files	*current;


	total = get_total(files);
	permissions = get_permissions(files);
	current = (*files);
	/*
	ft_putstr("TOTAL ");
	ft_putnbr(total);
	ft_putstr("\n");
	while (current->next != NULL)
	{
		if (current->name[0] == '.')
			current = current->next;
		ft_putendl(current->name);
		current = current->next;
	}
	printf("TOTAL : %d\n", total);
	*/
	exit(1);
}

int			get_total(t_files **files)
{
	t_files		*current;
	struct stat	s_file;
	int			total;

	current = (*files);
	total = 0;
	while (current)
	{
		stat(current->name, &s_file);
		total = total + s_file.st_blocks;
		current = current->next;
	}
	return (total);
}

char		*get_permissions(t_files **files)
{
	/*
	** TODO
	*/
}