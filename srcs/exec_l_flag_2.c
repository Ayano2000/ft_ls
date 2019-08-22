/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 13:48:58 by ayano             #+#    #+#             */
/*   Updated: 2019/08/22 13:48:59 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		find_longest(t_files **files)
{
	t_files			*current;
	int 			i;
	struct stat		ret;
	struct passwd	*pwd;

	current = (*files);
	i = 0;
	while (current->next != NULL)
	{
		stat(current->name, &ret);
		if ((pwd = getpwuid(ret.st_uid)) != NULL)
			if (ft_strlen(pwd->pw_name) > i)
				i = ft_strlen(pwd->pw_name);
		current = current->next;
	}
	return (i);
}

int		find_longest_grp(t_files **files)
{
	t_files			*current;
	int 			i;
	struct stat		ret;
	struct group	*grp;

	current = (*files);
	i = 0;
	while (current->next != NULL)
	{
		stat(current->name, &ret);
		if ((grp = getgrgid(ret.st_gid)) != NULL)
			if (ft_strlen(grp->gr_name) > i)
				i = ft_strlen(grp->gr_name);
		current = current->next;
	}
	return (i);
}