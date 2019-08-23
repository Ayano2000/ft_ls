/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_R_flag_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/23 12:05:18 by ayano             #+#    #+#             */
/*   Updated: 2019/08/23 12:07:59 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int		longest_name(t_files **files)
{
	t_files		*current;
	int			i;

	current = (*files);
	i = 0;
	while (current->next != NULL)
	{
		if (ft_strlen(current->name) > i)
			i = ft_strlen(current->name);
		current = current->next;
	}
	return (i);
}