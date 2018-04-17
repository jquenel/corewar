# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquenel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 01:45:17 by jquenel           #+#    #+#              #
#    Updated: 2018/03/20 12:52:05 by jquenel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		PS

##
##		CHECKER MAIN SOURCE
##

P1=			checker

MAIN1=		srcs/checker.c

##
##		PUSH_SWAP MAIN SOURCE
##

P2=			push_swap

MAIN2=		srcs/push_swap.c

##
##		SHARED RESSOURCES
##

SRC_PATH=	srcs

OBJ_PATH=	obj

CPPFLAGS=	-Iincludes

SRC_NAME=	ps_tools.c\
			ps_tools2.c\
			ps_tools3.c\
			ps_flags.c\
			ps_simplifier.c\
			ps_stkmini.c\
			ps_stkquick.c\
			ps_stksmall.c\
			ps_bogo.c\
			ps_stdsort.c\
			ps_optimizer.c\
			ps_remove_idiots.c\
			ps_checker_helpers.c\
			ft_btree_int.c\
			ft_rlst.c\
			ft_rlstdel.c\

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Werror -Wextra -Wall -O3 #-fsanitize=address

CC=			clang

LDFLAGS=	-Llibft_pf

LIBS=		-lft

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		Compile with all to get the two programs.
##		Compile using the program's name to recompile that program.
##		Compile with test for special testing purposes.
##

all:			$(NAME)

$(NAME):		c_lib $(P1) $(P2)

c_lib:
				@$(MAKE) -C libft_pf

$(P1):			$(MAIN1) $(OBJ)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(P2):			$(MAIN2) $(OBJ)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

##
##		Use fclean to clean this program.
##

clean:
				@rm -Rf $(OBJ_PATH)
				@echo "clean"

fclean:			clean
				@rm -f $(P1) $(P2)
				@echo "fclean"

lclean:			fclean
				@$(MAKE) fclean -C libft_pf
				@echo "lclean"

re:				fclean all

lre:			lclean re

.PHONY:			all clean fclean re lclean re
