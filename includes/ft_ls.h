/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:05:51 by ayano             #+#    #+#             */
/*   Updated: 2019/08/23 09:16:55 by ayano            ###   ########.fr       */
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
# include <sys/stat.h>
# include "../libft/libft.h"

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
void					get_permissions(t_files **files);

/*
** functions for the -l flag
*/
int						get_total(t_files **files);
t_files					*exec_l_flag(t_files **files);
void					get_nb_files(t_files **files);
void					get_user_id(t_files **files);
void					get_group_id(t_files **files, int max_len);
void					get_file_size(t_files **files);
void					get_file_size_help_print(int nb);
void					get_time(t_files **files);
char					**order_files_l(t_files **files);
char					**allocate_and_fill(int size, t_files **files);
int						is_sorted(char **array);
void					sort_by_ascii(char	**array);
int						find_longest(t_files **files);
int						find_longest_grp(t_files **files);


#endif