/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 21:18:18 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 21:18:21 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void       output(char **order, t_files **data)
{
    t_files     *head;
    int         i;

    i = 0;
    while (order[i] != '\0')
    {
        head = (*data);
        while(head->next != NULL) {
            if (ft_strcmp(head->name, order[i]) == 0)
            {
                ft_padstr(head->permissions, 10);
                ft_putnbr(head->links);
                ft_putchar(' ');
                ft_padstr(head->user, 5);
                ft_padstr(head->group, 12);
                ft_padstr(head->size, 12);
                ft_padstr(head->name, 12);
                ft_padstr(head->time, 12);
                break ;
            }
            head = head->next;
        }
        i++;
    }
}