NAME=		corewar

##
##		RESSOURCES
##

SRC_PATH=	srcs

OBJ_PATH=	obj

CPPFLAGS=	-Iincludes -I../libft/includes -I../libsdl/includes/SDL2

SRC_NAME=	corewar.c\
			op.c\
			basic_function.c\
			check_alive.c\
			control.c\
			copy_data.c\
			core_getlvalue.c\
			core_getvalue.c\
			core_regtomem.c\
			count_players.c\
			create_player.c\
			create_t_visu.c\
			cycle.c\
			declare_winner.c\
			decode_types.c\
			destroy_processes.c\
			destroy_t_visu.c\
			do_op.c\
			draw_image.c\
			draw_shape.c\
			draw_text.c\
			dtoi.c\
			dump_core.c\
			get_options.c\
			get_regs.c\
			init_optab.c\
			introduce_champions.c\
			is_all_nums.c\
			load_program.c\
			malloc_error.c\
			num_error.c\
			parser.c\
			plan_op.c\
			start_battle.c\
			t_vect.c\
			draw_pc.c\
			draw_menu.c\
			draw_core.c\
			draw_info.c\
			corewar_add.c\
			corewar_aff.c\
			corewar_and.c\
			corewar_div.c\
			corewar_fork.c\
			corewar_ld.c\
			corewar_ldi.c\
			corewar_lfork.c\
			corewar_live.c\
			corewar_lld.c\
			corewar_lldi.c\
			corewar_mul.c\
			corewar_not.c\
			corewar_or.c\
			corewar_st.c\
			corewar_sti.c\
			corewar_sub.c\
			corewar_vic.c\
			corewar_xor.c\
			corewar_zjmp.c\
			reset_visu.c\
			ft_strbonus.c\
			fps_handler.c\
			color_handler.c\
			screen_handler.c\
			set_t_typo.c\
			poor_itoa.c\
			set_texture_list.c\
			sound_intro.c\
			draw_selected.c\
			draw_register.c\
			draw_help.c\
			typo_handler.c\
			draw_finish.c\
			final_draw_menu.c\
			exit_corewar.c\
			final_control.c\
			play_sound.c

SRC=		$(addprefix $(SRC_PATH)/,$(SRC_NAME))

OBJ=		$(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

OBJ_NAME=	$(SRC_NAME:.c=.o)

##
##		COMPILER FLAGS
##

CFLAGS=		-g -fsanitize=address

CC=			gcc

LDFLAGS=	-L../libft -L../ft_printf -L../libsdl/lib

LIBS=		-lftprintf -lft -lSDL2 -lSDL2_image -lfreetype -lSDL2_ttf -lSDL2_mixer

LDLIBS=		$(LDFLAGS) $(LIBS)

##
##		SDL FILES
##

SDL_HEADER_NAME = 		SDL.h\
					SDL_assert.h\
					SDL_atomic.h\
					SDL_audio.h\
					SDL_bits.h\
					SDL_blendmode.h\
					SDL_clipboard.h\
					SDL_cpuinfo.h\
					SDL_egl.h\
					SDL_endian.h\
					SDL_error.h\
					SDL_events.h\
					SDL_filesystem.h\
					SDL_gamecontroller.h\
					SDL_gesture.h\
					SDL_haptic.h\
					SDL_hints.h\
					SDL_joystick.h\
					SDL_keyboard.h\
					SDL_keycode.h\
					SDL_loadso.h\
					SDL_log.h\
					SDL_main.h\
					SDL_messagebox.h\
					SDL_mouse.h\
					SDL_mutex.h\
					SDL_name.h\
					SDL_opengl.h\
					SDL_opengl_glext.h\
					SDL_opengles.h\
					SDL_opengles2_gl2ext.h\
					SDL_opengles2_gl2.h\
					SDL_opengles2_gl2platform.h\
					SDL_opengles2.h\
					SDL_opengles2_khrplatform.h\
					SDL_pixels.h\
					SDL_platform.h\
					SDL_power.h\
					SDL_quit.h\
					SDL_rect.h\
					SDL_render.h\
					SDL_rwops.h\
					SDL_scancode.h\
					SDL_shape.h\
					SDL_stdinc.h\
					SDL_surface.h\
					SDL_system.h\
					SDL_syswm.h\
					SDL_thread.h\
					SDL_timer.h\
					SDL_touch.h\
					SDL_types.h\
					SDL_version.h\
					SDL_video.h\
					SDL_vulkan.h\
					begin_code.h\
					close_code.h\
					SDL_mixer.h\
					SDL_ttf.h\
					SDL_image.h

SDL_LIBS_NAME =			\
					libSDL2_ttf.la\
					libSDL2_mixer-2.0.0.dylib\
					libSDL2-2.0.0.dylib\
					libSDL2_mixer.a\
					libSDL2main.a\
					libSDL2.a\
					libSDL2_mixer.dylib\
					libSDL2main.la\
					libSDL2.dylib\
					libSDL2_mixer.la\
					libfreetype.6.dylib\
					libSDL2.la\
					libSDL2_test.a\
					libfreetype.a\
					libSDL2_image-2.0.0.dylib\
					libSDL2_test.la\
					libfreetype.dylib\
					libSDL2_image.a\
					libSDL2_ttf-2.0.0.dylib\
				 	libfreetype.la\
					libSDL2_image.dylib\
					libSDL2_ttf.a\
					libSDL2_image.la\
					libSDL2_ttf.dylib\

SDL_LIBS_PATH = 		../libsdl/lib/

SDL_HEADER_PATH =		../libsdl/includes/SDL2/

SDL_LIBS =		$(addprefix $(SDL_LIBS_PATH), $(SDL_LIBS_NAME))

SDL_HEADER =	$(addprefix $(SDL_HEADER_PATH), $(SDL_HEADER_NAME))


##
##		Compile using the program's name to recompile that program.
##		Compile with test for special testing purposes.
##

all:			clibs $(NAME)

check_sdl:


clibs:
				$(MAKE) -C ../libft
				$(MAKE) -C ../ft_printf
				@$(foreach file, $(SDL_LIBS),  test ! -f $(file) && make sdl ; echo "\rchecking a sdl file\c" ;)
				@$(foreach file, $(SDL_HEADER),  test ! -f $(file) && make sdl ; echo "\rchecking sdl files...\c" ;)
				@echo "SDL IS READY"


$(NAME):		$(OBJ)
				$(CC) $(CFLAGS) $(CPPFLAGS) $^ -o $@ $(LDLIBS)
				@echo "compiled $@."

$(OBJ_PATH)/%.o:$(SRC_PATH)/%.c
				@mkdir $(OBJ_PATH) 2> /dev/null || true
				$(CC) $(CFLAGS) -o $@ -c $< $(CPPFLAGS)

LOCATION =		PWD

sdl:
				if [ ! -d $(HOME)"/goinfre/sdl" ] ; then git clone http://github.com/hyarius/sdl ~/goinfre/sdl ; fi
				if [ ! -d "../libsdl" ] ; then mkdir ../libsdl ; fi
				if [ ! -d "../libsdl/lib" ] ; then mkdir ../libsdl/lib ; fi
				if [ ! -d "../libsdl/includes" ] ; then mkdir ../libsdl/includes ; fi
				@make -C ~/goinfre/sdl
				@cp -rf ~/goinfre/sdl/FREETYPE/lib ../libsdl
				@cp -rf ~/goinfre/sdl/SDL2/lib ../libsdl
				@cp -rf ~/goinfre/sdl/SDL2_IMAGE/lib ../libsdl
				@cp -rf ~/goinfre/sdl/SDL2_TTF/lib ../libsdl
				@cp -rf ~/goinfre/sdl/SDL2_MIXER/lib ../libsdl
				@cp -rf ~/goinfre/sdl/SDL2/include/SDL2 ../libsdl/includes
				@cp -rf ~/goinfre/sdl/SDL2_IMAGE/include/SDL2 ../libsdl/includes
				@cp -rf ~/goinfre/sdl/SDL2_TTF/include/SDL2 ../libsdl/includes
				@cp -rf ~/goinfre/sdl/SDL2_MIXER/include/SDL2 ../libsdl/includes

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
