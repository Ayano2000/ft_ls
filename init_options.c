/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:04:46 by ayano             #+#    #+#             */
/*   Updated: 2019/08/19 15:21:34 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_options	*init_options(int argc, char **argv)
{
	t_options	*options;

	options = (t_options *)malloc(sizeof(t_options));
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->R = 0;
	options->t = 0;
	set_options(&options, argc, argv);
	return (options);
}