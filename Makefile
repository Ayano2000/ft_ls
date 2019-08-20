# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayano <ayano@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 16:26:03 by ayano             #+#    #+#              #
#    Updated: 2019/08/20 09:12:40 by ayano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_ls:
	gcc -o ft_ls -g ft_ls.c init_options.c libft/libft.a nodes.c exec_options.c exec_l_flag.c
	
fclean:
	@$(RM) ./ft_ls

re: fclean ft_ls
