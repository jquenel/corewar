# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jquenel <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/15 01:45:17 by jquenel           #+#    #+#              #
#    Updated: 2018/04/17 12:20:01 by jquenel          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=		Corewar

##
##		CHECKER MAIN SOURCE
##

P1=			asm

##
##		PUSH_SWAP MAIN SOURCE
##

P2=			corewar

##
##		SHARED RESSOURCES
##

SRC_PATH=	srcs

OBJ_PATH=	objs

CPPFLAGS=	-Iincludes

HEAD_A=		includes/asm.h\
			includes/libft.h\
			t_op.h\

HEAD_B=		includes/corewar.h\
			includes/libft.h\
			t_op.h\

SRC_ASM=	\

SRC_CORE=	\

SRC_A=		$(addprefix $(SRC_PATH)/,$(SRC_ASM))

SRC_C=		$(addprefix $(SRC_PATH)/,$(SRC_CORE))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_A=		$(SRC_A:.c=.o)

OBJ_C=		$(SRC_C:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Werror -Wextra -Wall -O3 #-fsanitize=address

CC=			clang

LDFLAGS=	-Llibft

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

$(P1):			$(OBJ_A)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(P2):			$(OBJ_C)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(OBJ_A)/%.o:	$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

$(OBJ_C)/%.o:	$(SRC_PATH)/%.c
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
