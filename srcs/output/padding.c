/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   padding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayano <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 23:40:30 by ayano             #+#    #+#             */
/*   Updated: 2020/01/16 23:40:31 by ayano            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_ls.h"

void    ft_padstr(char *str, int length)
{
    int     len;

    len = ft_strlen(str) - 1;
    ft_putstr(str);
    while(len <= length)
    {
        ft_putchar(' ');
        len++;
    }
    return ;
}