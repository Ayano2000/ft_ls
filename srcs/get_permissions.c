/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_permissions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/26 08:49:38 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 09:17:58 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** This will get the permissions and set it to be in the perm char * in the 
** files struct.
*/
void	get_permissions(t_files **files)
{
    // TO FIX. THIS JUST OUTPUTS THE PERMISSIONS AND DOESNT SET THEM TO THE
    // STRING IN THE STRUCT.
	t_files			*current;
	struct stat		ret;

	current = (*files);
	stat(current->name, &ret);
	ft_putchar( (S_ISDIR(ret.st_mode)) ? 'd' : '-');
    ft_putchar( (ret.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar( (ret.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar( (ret.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXOTH) ? 'x' : '-');
}