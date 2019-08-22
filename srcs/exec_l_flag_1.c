/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_l_flag_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 13:14:01 by ayano             #+#    #+#             */
/*   Updated: 2019/08/21 13:14:03 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

void	get_group_id(t_files **files)
{
	t_files			*current;
	struct stat		ret;
	struct group	*grp;
	int				i;

	i = 0;
	stat(current->name, &ret);
	if ((grp = getgrgid(ret.st_gid)) != NULL)
	{
		ft_putstr("  ");
		if (ft_strlen(grp->gr_name) <= 5)
			ft_putstr(grp->gr_name);
		else
			while (i < 5)
			{
				ft_putchar(grp->gr_name[i]);
				i++;
			}
	} 
}

void	get_file_size(t_files **files)
{
	t_files			*current;
	struct stat		ret;

	stat(current->name, &ret);
	if (ret.st_size < 10)
	{
		ft_putstr("      ");
		ft_putnbr(ret.st_size);
	}
	else if (ret.st_size < 100 && ret.st_size > 9)
	{
		ft_putstr("     ");
		ft_putnbr(ret.st_size);
	}
	else if (ret.st_size < 1000 && ret.st_size > 99)
	{
		ft_putstr("    ");
		ft_putnbr(ret.st_size);
	}
	else
		return(get_file_size_help_print(ret.st_size));
}

void	get_file_size_help_print(int nb)
{
	if (nb < 10000 && nb > 999)
	{
		ft_putstr("   ");
		ft_putnbr(nb);
	}
	else if (nb < 100000 && nb > 9999)
	{
		ft_putstr("  ");
		ft_putnbr(nb);
	}
	else if (nb < 1000000 && nb > 99999)
	{
		ft_putstr(" ");
		ft_putnbr(nb);
	}
	else if (nb < 10000000 && nb > 999999)
	{
		ft_putnbr(nb);
	}
}

void	get_time(t_files **files)
{
	t_files			*current;
	struct stat		ret;
	char			**time;
	int				i;

	i = 0;
	stat(current->name, &ret);
	time = ft_strsplit(ctime(&ret.st_mtime), ' ');
	ft_putchar(' ');
	if (ft_strlen(time[2]) == 1)
	{
		ft_putchar(' ');
		ft_putstr(time[2]);
	}
	else
		ft_putstr(time[2]);
	ft_putchar(' ');
	ft_putstr(time[1]);
	ft_putchar(' ');
	while (i < 5)
	{
		ft_putchar(time[3][i]);
		i++;
	}
	ft_putchar(' ');
}