/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:05:51 by ayano             #+#    #+#             */
/*   Updated: 2019/08/19 16:21:30 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <unistd.h>
# include <dirent.h>
# include <sys/types.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct			s_options
{
	int					r : 1;
	int					l : 1;
	int					a : 1;
	int					t : 1;
	int					R : 1;					
}						t_options;

/*
** functions to set options, check errors and
** initialize the struct.
*/
t_options				*init_options(int argc, char **argv);
void					set_options(t_options **options, int argc, char **argv);
void					check_input(int argc, char **argv);


#endif