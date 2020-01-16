/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:33:04 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 16:33:05 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *set_time(t_files **current)
{
    t_files			*head;
	t_files			*cursor;
	struct stat		ret;
	char			**time;
    int             i;
    int             x;

    head = (*current);
    cursor = head;
    while (cursor)
    {
        i = 0;
        x = 0;
        stat(cursor->name, &ret);
        cursor->time = ft_strdup(ctime(&ret.st_mtime));
        cursor = cursor->next;
    }
    return (head);
}