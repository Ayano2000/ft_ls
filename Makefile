# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayano <ayano@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 16:26:03 by ayano             #+#    #+#              #
#    Updated: 2019/08/19 16:27:30 by ayano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_ls:
	gcc -o ft_ls -g ft_ls.c init_options.c libft/libft.a
fclean:
	@$(RM) ./checker
	@$(RM) ./push_swap

re: fclean push_swap checke
