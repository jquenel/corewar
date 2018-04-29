NAME=		corewar

##
##		RESSOURCES
##

SRC_PATH=	srcs

OBJ_PATH=	obj

CPPFLAGS=	-Iincludes -I../libft/includes

SRC_NAME=	corewar.c\
			core_getvalue.c\
			core_getlvalue.c\
			core_regtomem.c\
			copy_data.c\
			count_players.c\
			create_player.c\
			dump_core.c\
			ft_convert.c\
			destroy_processes.c\
			get_options.c\
			load_program.c\
			malloc_error.c\
			parser.c\
			create_player.c\
			dump_core.c\
			is_all_nums.c\
			start_battle.c\
			init_optab.c\
			live.c\
			ld.c\
			st.c\
			add.c\
			sub.c\
			and.c\
			or.c\
			xor.c\
			zjmp.c\
			ldi.c\
			sti.c\
			fork.c\
			lld.c\
			lldi.c\
			lfork.c\
			aff.c\

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -Werror -g -fsanitize=address

CC=			gcc

LDFLAGS=	-L../libft -L../ft_printf

LIBS=		-lftprintf -lft

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		Compile using the program's name to recompile that program.
##		Compile with test for special testing purposes.
##

all:			clibs $(NAME)

clibs:
				@$(MAKE) -C ../libft
				@$(MAKE) -C ../ft_printf

$(NAME):		$(OBJ)
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
				@rm -f $(NAME)
				@echo "fclean"

re:				fclean all

.PHONY:			all clean fclean re
