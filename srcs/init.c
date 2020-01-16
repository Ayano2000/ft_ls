/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/15 15:52:33 by ayano             #+#    #+#             */
/*   Updated: 2020/01/15 15:52:35 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_options   *init_options(int argc, char **argv) {
    t_options   *flags;
    char        *input;
    int         i;
    
    i = 1;
    flags = (t_options *)malloc(sizeof(t_options) * 1);
    input = (char *)malloc(sizeof(char) * (ft_strlen(argv[1]) + 1));

    while (argv[1][i] != '\0') {
        if (argv[1][i] != ' ') {
            free(input);
            free(flags);
            write(1, "EXITING\n", 7);
            exit(1);
        }
        input[i - 1] = argv[1][i];
        i++;
    }
    input[i] = '\0';
    flags->options = ft_strdup(input);
    return (flags);
}