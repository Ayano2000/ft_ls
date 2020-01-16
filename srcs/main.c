/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:50:58 by ayano             #+#    #+#             */
/*   Updated: 2020/01/15 15:50:59 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

int     main(int argc, char **argv) {
    t_options   *options;
    t_files     *files;

    files = init_files();
    files = get_files(&files);
    files = set_users(&files);
    files = set_groups(&files);
    files = set_size(&files);
    files = set_time(&files);
    files = set_permissions(&files);
    files = set_links(&files);
    output(&files);
    if (argc > 1) {
        options = parse(argc, argv);
    }


    return (0);

}