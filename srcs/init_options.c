/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_options.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 15:04:46 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 09:34:30 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

/*
** malloc the struct and initialzie the variables.
*/
t_options	*init_options(int argc, char **argv)
{
	t_options	*options;

	options = (t_options *)malloc(sizeof(t_options));
	options->a = 0;
	options->l = 0;
	options->r = 0;
	options->R = 0;
	options->t = 0;
	check_input(argc, argv);
	set_options(&options, argc, argv);
	return (options);
}

/*
** set the values in the structto 1 if the flag is present.
*/
void		set_options(t_options **options, int argc, char **argv)
{
	int		i = 1;
	while (i < argc)
	{
		if (ft_strcmp(argv[i], "-a") == 0)
			(*options)->a = 1;
		if (ft_strcmp(argv[i], "-l") == 0)
			(*options)->l = 1;
		if (ft_strcmp(argv[i], "-t") == 0)
			(*options)->t = 1;
		if (ft_strcmp(argv[i], "-r") == 0)
			(*options)->r = 1;
		if (ft_strcmp(argv[i], "-R") == 0)
			(*options)->R = 1;
		i++;
	}
}

/*
** check for invalid input.
*/
void		check_input(int argc, char **argv)
{
	int		i;
	
	i = 1;
	while (argv[i] != '\0')
	{
		if (ft_strcmp(argv[i], "-a") != 0 && ft_strcmp(argv[i], "-l") != 0 &&
			ft_strcmp(argv[i], "-t") != 0 && ft_strcmp(argv[i], "-r") != 0 &&
				ft_strcmp(argv[i], "-R") != 0)
		{
			ft_putstr("ft_ls: illegal option -- ");
			ft_putchar(argv[i][1]);
			ft_putstr("\n");
			ft_putendl("usage: ls [-alrtR] [file ...]");
		}
		i++;
	}
}