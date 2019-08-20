/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:43:34 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 16:00:19 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files		*exec_l_flag(t_files **files)
{
	int		total;
	int		permissions;
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

int		get_permissions(t_files **files)
{
	t_files		*current;
	struct stat	ret;

	current = (*files);
	stat(current->name, &ret);
	printf("%d\n", ret.st_mode);
	return (0);
}


/*
int getChmod(const char *path){
    struct stat ret;

    if (stat(path, &ret) == -1) {
        return -1;
    }

    return (ret.st_mode & S_IRUSR)|(ret.st_mode & S_IWUSR)|(ret.st_mode & S_IXUSR)|
        (ret.st_mode & S_IRGRP)|(ret.st_mode & S_IWGRP)|(ret.st_mode & S_IXGRP)|
        (ret.st_mode & S_IROTH)|(ret.st_mode & S_IWOTH)|(ret.st_mode & S_IXOTH);
}
*/