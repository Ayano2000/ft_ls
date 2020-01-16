/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 16:13:47 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 16:13:49 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *set_size(t_files **current)
{
    t_files			*head;
    t_files			*cursor;
	struct stat		ret;

	head = (*current);
    cursor = head;
    while (cursor)
    {
	    stat(cursor->name, &ret);
        cursor->size = ft_strdup(ft_itoa(ret.st_size));
        cursor = cursor->next;
    }
    return (head);
}