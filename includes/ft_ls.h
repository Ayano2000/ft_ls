/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 14:05:51 by ayano             #+#    #+#             */
/*   Updated: 2019/08/26 08:47:02 by ayano            ###   ########.fr       */
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
# include <stdbool.h> 
# include "../libft/libft.h"

typedef struct	s_options
{
	char	*options;
	char	**targets;
}				t_options;

typedef struct  s_files
{
	char	*permissions;
	int		links;
	char	*user;
	char	*group;
	char	*size;
	char	*time;
	char	*name;
	struct	s_files	*next;
	struct	s_files	*previous;
}				t_files;

/* GATHERING INFO */
t_options		*parse(int argc, char **argv);
t_files			*get_files(t_files **files);
t_files			*init_files(void);
t_files			*add_node(t_files **head);
t_files			*set_users(t_files **current);
t_files			*set_groups(t_files **current);
t_files			*set_size(t_files **current);
t_files			*set_time(t_files **current);
t_files			*set_permissions(t_files **current);
t_files			*set_links(t_files **current);
t_files			*init_data(t_files **files);

/* OUTPUT HANDLING */
void			output(char **order, t_files **data);
void			ft_padstr(char *str, int length);
char			**ascii_sort(t_files **files);
int				is_sorted(char **array);
void			sort_by_ascii(char	**array);

#endif