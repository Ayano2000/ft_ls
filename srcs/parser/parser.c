/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 10:13:08 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 10:13:08 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

t_options   *parse(int argc, char **argv) {
    int i;
    int target_iterator;
    t_options *res;

    i = 2;
    target_iterator = 0;
    res = (t_options *)malloc(sizeof(t_options) * 1);
    if (argv[1][0] == '-') {
        res->options = ft_strdup(argv[1]);
    }
    if ((argc - 2) >= 1) {
        if (argc - 2 > 1) {
            res->targets = (char **)malloc(sizeof(char *) * (argc - 1));
            res->targets[argc - 1] = "\0";
        }
        while (argv[i] != '\0') {
            res->targets[target_iterator] = ft_strdup(argv[i]);
            target_iterator++;
            i++;
        }
    }
    return(res);
}