# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayano <ayano@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/08/19 16:26:03 by ayano             #+#    #+#              #
#    Updated: 2019/08/20 09:37:03 by ayano            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ft_ls:
	gcc -o ft_ls ./srcs/*.c ./srcs/parser/*.c ./srcs/output/*.c ./srcs/files/*.c ./libft/libft.a
	
fclean:
	@$(RM) ./ft_ls

re: fclean ft_ls
