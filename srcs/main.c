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
    t_options *options;
    if (argc > 1) {
        options = parse(argc, argv);
    }
    int i = 0;
    printf("FLASGS -> %s\n", options->options);
    while (options->targets[i] != '\0') {
        printf("options -> %s\n", options->targets[i]);
        i++;
    }
    return (0);
}