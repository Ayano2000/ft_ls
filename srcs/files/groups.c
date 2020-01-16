/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   groups.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:48:28 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 15:48:29 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *set_groups(t_files **current)
{
    t_files         *head;
    t_files         *cursor;
    struct stat     ret;
	struct group    *grp;

    head = (*current);
    cursor = (*current);
    while (cursor->next != NULL)
    {
        stat(cursor->name, &ret);
        if ((grp = getgrgid(ret.st_gid)) != NULL)
        {
            // printf("%s\n", grp->gr_name);
            cursor->group = ft_strdup(grp->gr_name);
        }
        cursor = cursor->next;
    }
    return (head);
}