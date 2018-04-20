# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquenel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 01:45:17 by jquenel           #+#    #+#              #
#    Updated: 2018/04/20 22:21:36 by jquenel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Corewar

P1=			asm
P1_PATH=	asm

P2=			corewar
P2_PATH=	corewar

all:			$(NAME)

$(NAME):		c_lib $(P1) $(P2)

c_lib:
				@$(MAKE) -C libft
				@$(MAKE) -C ft_printf

$(P1):
				@$(MAKE) -C $(P1_PATH)
				@cp $(P1_PATH)/$(P1) .

$(P2):
				@$(MAKE) -C $(P2_PATH)
				@cp $(P2_PATH)/$(P2) .

clean:
				@$(MAKE) -C libft clean
				@$(MAKE) -C ft_printf clean
				@$(MAKE) -C $(P1_PATH) clean
				@$(MAKE) -C $(P2_PATH) clean
				@echo "clean"

fclean:
				@$(MAKE) -C libft fclean
				@$(MAKE) -C ft_printf fclean
				@$(MAKE) -C $(P1_PATH) fclean
				@$(MAKE) -C $(P2_PATH) fclean
				@rm -f $(P1) $(P2)
				@echo "fclean"

re:				fclean all

.PHONY:			all clean fclean re
