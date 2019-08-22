/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   order_files_l.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 16:10:06 by ayano             #+#    #+#             */
/*   Updated: 2019/08/21 16:10:07 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_ls.h"

char		**order_files_l(t_files **files)
{
	int		size;
	t_files	*current;
	t_files	*cursor;
	char	**names;

	current = (*files);
	cursor = current;
	size = 0;
	while (cursor->next != NULL)
	{
		if (cursor->name[0] != '.')
			size++;
		cursor = cursor->next;
	}
	names = allocate_and_fill(size, &current);
	sort_by_ascii(names);
	int check = 0;
	return (names);
}

char		**allocate_and_fill(int size, t_files **files)
{
	t_files	*current;
	char	**array;
	int		i;

	current = (*files);
	array = (char **)malloc(sizeof(char *) * (size + 1));
	i = 0;
	while (current->next)
	{
		if (current->name[0] != '.')
		{
			array[i] = ft_strdup(current->name);
			current = current->next;
			i++;
		}
		else
			current = current->next;
	}
	array[i] = 0;
	return (array);
}

void	sort_by_ascii(char	**array)
{
	int		i;
	char	*temp;
	int		check;

	i = 0;
	check  = 0;
	while (array[i + 1] != '\0')
	{
		if (ft_strcmp(array[i], array[i + 1]) >= 0)
		{
			temp = ft_strdup(array[i]);
			free(array[i]);
			array[i] = ft_strdup(array[i + 1]);
			free(array[i + 1]);
			array[i + 1] = ft_strdup(temp);
			free(temp);
		}
		i++;
	}
	check = is_sorted(array);
	if (check == 0)
		sort_by_ascii(array);
}

int		is_sorted(char **array)
{
	int		i;

	i = 0;
	while (array[i + 1] != '\0')
	{
		if (ft_strcmp(array[i], array[i + 1]) != -1)
			return (0);
		i++;
	}
	return (1);
}