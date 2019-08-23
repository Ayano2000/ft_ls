/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:43:34 by ayano             #+#    #+#             */
/*   Updated: 2019/08/23 09:25:03 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files		*exec_l_flag(t_files **files)
{
	int				total;
	t_files			*current;
	char			**names;
	int				i;
	int				max_len;


	total = get_total(files);
	current = (*files);
	names = order_files_l(&current);
	i = 0;
	max_len = find_longest_grp(files);
	ft_putstr("TOTAL ");
	ft_putnbr(total);
	ft_putchar('\n');
	while (names[i] != '\0')
	{
		current = (*files);
		while (ft_strcmp(names[i], current->name) != 0)
			current = current->next;
		get_permissions(&current);
		get_nb_files(&current);
		get_user_id(&current);
		get_group_id(&current, max_len);
		get_file_size(&current);
		get_time(&current);
		ft_putstr(current->name);
		write(1, "\n", 1);
		i++;
	}
	exit(1);
}

int			get_total(t_files **files)
{
	t_files			*current;
	struct stat		ret;
	int				total;

	current = (*files);
	total = 0;
	while (current->next != NULL)
	{
		stat(current->name, &ret);
		total = total + ret.st_blocks;
		current = current->next;
	}
	return (total);
}

void	get_permissions(t_files **files)
{
	t_files			*current;
	struct stat		ret;

	current = (*files);
	stat(current->name, &ret);
	ft_putchar( (S_ISDIR(ret.st_mode)) ? 'd' : '-');
    ft_putchar( (ret.st_mode & S_IRUSR) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWUSR) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXUSR) ? 'x' : '-');
    ft_putchar( (ret.st_mode & S_IRGRP) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWGRP) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXGRP) ? 'x' : '-');
    ft_putchar( (ret.st_mode & S_IROTH) ? 'r' : '-');
    ft_putchar( (ret.st_mode & S_IWOTH) ? 'w' : '-');
    ft_putchar( (ret.st_mode & S_IXOTH) ? 'x' : '-');
}

void	get_nb_files(t_files **files)
{
	t_files			*current;
	struct stat		ret;
	stat(current->name, &ret);
	if (ret.st_nlink < 10)
	{
		ft_putstr("   ");
		ft_putnbr(ret.st_nlink);
	}
	else if (ret.st_nlink >= 10 && ret.st_nlink< 100)
	{
		ft_putstr("  ");
		ft_putnbr(ret.st_nlink);
	}
	else
	{
		ft_putstr(" ");
		ft_putnbr(ret.st_nlink);
	}
}

void	get_user_id(t_files **files)
{
	t_files			*current;
	struct stat		ret;
	struct passwd	*pwd;
	int				i;
	int				max_len;

	i = 0;
	stat(current->name, &ret);
	max_len = find_longest(files);
	if ((pwd = getpwuid(ret.st_uid)) != NULL)
	{
		if (ft_strlen(pwd->pw_name) < max_len)
		{
			i = ft_strlen(pwd->pw_name);
			ft_putchar(' ');
			ft_putstr(pwd->pw_name);
			while (i < max_len)
			{
				ft_putchar(' ');
				i++;
			}
		}
		else
		{
			ft_putchar(' ');
			ft_putstr(pwd->pw_name);
		}
	}
}