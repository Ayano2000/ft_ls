/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ascii_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 01:40:17 by ayano             #+#    #+#             */
/*   Updated: 2020/01/17 01:40:18 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

char	**ascii_sort(t_files **files)
{
	char	**names;
	int		size;
	t_files *current;

	current = (*files);
	while (current->next)
	{
		current = current->next;
		size++;
	}
	names = (char **)malloc(sizeof(char *) * size + 1);
	names[size] = 0;
	current = (*files);
	size = 0;
	while (current->next != NULL)
	{
		names[size] = ft_strdup(current->name);
		current = current->next;
		size++;
	}
	sort_by_ascii(names);
	return (names);
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