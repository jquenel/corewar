# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jboissy <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/05/25 15:14:56 by jboissy           #+#    #+#              #
#    Updated: 2018/05/25 15:33:57 by jboissy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

VM_PATH =				corewar

ASM_PATH =				asm

LIBFT_PATH =			libft

PRINTF_PATH =			ft_printf

all:
	$(MAKE) $(MFLAGS) -C $(LIBFT_PATH)
	$(MAKE) $(MFLAGS) -C $(PRINTF_PATH)
	$(MAKE) $(MFLAGS) -C $(ASM_PATH)
	$(MAKE) $(MFLAGS) -C $(VM_PATH)

re:		fclean all

clean:
	$(MAKE) $(MFLAGS) -C $(LIBFT_PATH) clean
	$(MAKE) $(MFLAGS) -C $(PRINTF_PATH) clean
	$(MAKE) $(MFLAGS) -C $(ASM_PATH) clean
	$(MAKE) $(MFLAGS) -C $(VM_PATH) clean

fclean:
	$(MAKE) $(MFLAGS) -C $(LIBFT_PATH) fclean
	$(MAKE) $(MFLAGS) -C $(PRINTF_PATH) fclean
	$(MAKE) $(MFLAGS) -C $(ASM_PATH) fclean
	$(MAKE) $(MFLAGS) -C $(VM_PATH) fclean

sdl:
	$(MAKE) $(MFLAGS) -C $(VM_PATH) sdl

.PHONY: sdl fclean clean re all
