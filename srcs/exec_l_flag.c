/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <ayano@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/20 09:43:34 by ayano             #+#    #+#             */
/*   Updated: 2019/08/20 17:31:46 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

t_files		*exec_l_flag(t_files **files)
{
	int				total;
	t_files			*current;


	total = get_total(files);
	current = (*files);
	printf("TOTAL %d\n", total);
	while (current->next != NULL)
	{
		get_permissions(&current);
		get_nb_files(&current);
		get_user_id(&current);
		get_group_id(&current);
		get_file_size(&current);
		get_time(&current);
		write(1, "\n", 1);
		current = current->next;
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

	stat(current->name, &ret);
	if ((pwd = getpwuid(ret.st_uid)) != NULL)
	{
		ft_putchar(' ');
		ft_putstr(pwd->pw_name);
	}
}