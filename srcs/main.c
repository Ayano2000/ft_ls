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
    char        **order;

    files = init_files();
    files = init_data(&files);
    files = add_subdir(&files);
    /* order = ascii_sort(&files); */ /* WORKS */
    if (argc > 1) {
        options = parse(argc, argv);
    }
    // output(&files);
    return (0);

}