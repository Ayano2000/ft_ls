/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:05:51 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 09:31:54 by ayano            ###   ########.fr       */
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
	int					r;
	int					l;
	int					a;
	int					t;
	int					R;					
}						t_options;

typedef struct			s_files
{
	char				*name;
	int					time;
	struct s_files		*head;
	struct s_files		*next;
	struct s_files		*prev;
}						t_files;

/*
** functions to handle the node creation and freeing.
*/
t_files					*add_node(t_files **head);

/*
** functions to set options, check errors and
** initialize the struct.
*/
t_options				*init_options(int argc, char **argv);
void					set_options(t_options **options, int argc, char **argv);
void					check_input(int argc, char **argv);

/*
** function that determines which function to call
** and then prints the resultant.
*/
void					exec_options(t_options **options);
t_files					*init_files(void);

/*
** functions for all flags.
*/
t_files					*get_files(t_files **files);

#endif