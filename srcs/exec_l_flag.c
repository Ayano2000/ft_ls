/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:43:34 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 16:44:57 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files		*exec_l_flag(t_files **files)
{
	int		total;
	t_files	*current;


	total = get_total(files);
	get_permissions(files);
	current = (*files);
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

void	get_permissions(t_files **files)
{
	t_files		*current;
	struct stat	ret;

	current = (*files);
	stat(current->name, &ret);
	ft_putchar( (S_ISDIR(ret.st_mode)) ? 'd' : '-');
    ft_putchar( (ret.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar( (ret.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar( (ret.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXOTH) ? 'x' : '-');
}