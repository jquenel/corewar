NAME=		corewar

##
##		RESSOURCES
##

SRC_PATH=	srcs

OBJ_PATH=	obj

CPPFLAGS=	-Iincludes -Ilibft/includes -Ilibsdl/includes

SRC_NAME=	add.c\
			aff.c\
			and.c\
			basic_function.c\
			control.c\
			copy_data.c\
			core_getlvalue.c\
			core_getvalue.c\
			core_regtomem.c\
			corewar.c\
			count_players.c\
			create_player.c\
			cycle.c\
			declare_winner.c\
			destroy_processes.c\
			do_op.c\
			draw_image.c\
			draw_shape.c\
			draw_text.c\
			dtoi.c\
			dump_core.c\
			fork.c\
			get_options.c\
			init_optab.c\
			initialisation.c\
			is_all_nums.c\
			ld.c\
			ldi.c\
			lfork.c\
			live.c\
			lld.c\
			lldi.c\
			load_program.c\
			malloc_error.c\
			or.c\
			parser.c\
			plan_op.c\
			st.c\
			start_battle.c\
			sti.c\
			sub.c\
			t_coord.c\
			t_core.c\
			visualizer.c\
			xor.c\
			zjmp.c

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		SDL INCLUDE/LIB
##

SDL2_MAIN_SRC =				SDL2

SDL2_IMAGE_SRC =			SDL2_image

SDL2_TTF_SRC =				SDL2_ttf

FREETYPE_SRC =				freetype

SDL2_PATH =					sdl

INCLUDE_SDL2 =				sdl/includes

##
##		COMPILER FLAGS
##

CFLAGS=		-Wextra -Wall -Werror -g -fsanitize=address

CC=			gcc

LDFLAGS=	-Llibft -Lft_printf -Llibsdl/lib

LIBS=		-lftprintf -lft -lSDL2 -lSDL2_image -lfreetype -lSDL2_ttf

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		Compile using the program's name to recompile that program.
##		Compile with test for special testing purposes.
##

all:			clibs $(NAME)

clibs:
				@$(MAKE) -C ../libft
				@$(MAKE) -C ../ft_printf
				@cp -rf ~/goinfre/sdl/FREETYPE/lib libsdl
				@cp -rf ~/goinfre/sdl/SDL2/lib libsdl
				@cp -rf ~/goinfre/sdl/SDL2_IMAGE/lib libsdl
				@cp -rf ~/goinfre/sdl/SDL2_TTF/lib libsdl

$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

sdl:
				@make -C ~/goinfre/sdl
				@cp -rf ~/goinfre/sdl/FREETYPE/lib libsdl
				@cp -rf ~/goinfre/sdl/SDL2/lib libsdl
				@cp -rf ~/goinfre/sdl/SDL2_IMAGE/lib libsdl
				@cp -rf ~/goinfre/sdl/SDL2_TTF/lib libsdl

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
