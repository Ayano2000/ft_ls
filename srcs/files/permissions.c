/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permissions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 17:12:38 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 17:12:40 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *set_permissions(t_files **current)
{
	t_files     *head;
	t_files     *cursor;
    struct stat ret;
	
    head = (*current);
    cursor = head;
    while (cursor)
    {
        cursor->permissions = (char *)malloc(sizeof(char) * 11);
        cursor->permissions[11] = '\0';
        stat(cursor->name, &ret);
        cursor->permissions[0] = (S_ISDIR(ret.st_mode)) ? 'd' : '-';
        cursor->permissions[1] = (ret.st_mode & S_IRUSR) ? 'r' : '-';
        cursor->permissions[2] = (ret.st_mode & S_IWUSR) ? 'w' : '-';
        cursor->permissions[3] = (ret.st_mode & S_IXUSR) ? 'x' : '-';
        cursor->permissions[4] = (ret.st_mode & S_IRGRP) ? 'r' : '-';
        cursor->permissions[5] = (ret.st_mode & S_IWGRP) ? 'w' : '-';
        cursor->permissions[6] = (ret.st_mode & S_IXGRP) ? 'x' : '-';
        cursor->permissions[7] = (ret.st_mode & S_IROTH) ? 'r' : '-';
        cursor->permissions[8] = (ret.st_mode & S_IWOTH) ? 'w' : '-';
        cursor->permissions[9] = (ret.st_mode & S_IXOTH) ? 'x' : '-';
        cursor = cursor->next;
    };
    return (head);
}