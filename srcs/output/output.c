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

void       output(t_files **data)
{
    t_files     *head;

    head = (*data);
    while(head->next != NULL) {
        ft_padstr(head->permissions, 10);
        ft_putnbr(head->links);
        ft_putchar(' ');
        ft_padstr(head->user, 5);
        ft_padstr(head->group, 9);
        ft_padstr(head->size, 12);
        ft_padstr(head->name, 12);
        ft_padstr(head->time, 12);
        head = head->next;
    }
}