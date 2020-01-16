/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:27:29 by ayano             #+#    #+#             */
/*   Updated: 2020/01/17 01:27:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_files     *init_data(t_files **files)
{
    (*files) = get_files(files);
    (*files) = set_users(files);
    (*files) = set_groups(files);
    (*files) = set_size(files);
    (*files) = set_time(files);
    (*files) = set_permissions(files);
    (*files) = set_links(files);
    return (*files);
}