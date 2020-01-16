/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   links.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:26:50 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 17:26:52 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *set_links(t_files **current)
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
        cursor->links = ret.st_nlink;
        cursor = cursor->next;
    }
    return (head);
}