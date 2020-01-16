/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   users.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 15:39:01 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 15:39:02 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *set_users(t_files **current)
{
    t_files         *head;
    t_files         *cursor;
    struct stat     ret;
	struct passwd   *pwd;

    head = (*current);
    cursor = (*current);
    while (cursor->next != NULL)
    {
        stat(cursor->name, &ret);
        if ((pwd = getpwuid(ret.st_uid)) != NULL)
        {
            cursor->user = ft_strdup(pwd->pw_name);
        }
        cursor = cursor->next;
    }
    return (head);
}