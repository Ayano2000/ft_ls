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
        printf("%-12s", head->permissions);
        printf("%d ", head->links);
        printf("%-7s", head->user);
        printf("%-12s", head->group);
        printf("%-12s ", head->size);
        printf("%-12s ", head->name);
        printf("%-12s", head->time);
        printf("\n");
        head = head->next;
    }
}