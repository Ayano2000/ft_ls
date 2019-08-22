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
	int				i;
	struct stat		ret;
	struct passwd	*pwd;
	char			*str;
	
	stat(current->name, &ret);
	pwd = getpwuid(ret.st_uid);
	current = (*files);
	str = ft_strdup(pwd->pw_name);
	i = ft_strlen(str);
	free(str);
	while (current->next)
	{
		stat(current->name, &ret);
		pwd = getpwuid(ret.st_uid);
		str = ft_strdup(pwd->pw_name);
		if (ft_strlen(str) > i)
			i = ft_strlen(str);
		free(str);
		current = current->next;
	}
	printf("LONGEST : %d\n", i);
	return (i);
}