CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I../libft/includes -I../ft_printf
LDFLAGS := -L../ft_printf -lftprintf -L../libft -lft

NAME := asm

SRCS := \
	ast.c compile.c lexer.c main.c op.c parser.c semantics.c utils.c xmalloc.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

.PHONY:	all
all:	$(NAME)

-include $(DEPS)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $^ $(LDFLAGS) -o $@

.PHONY:	clean fclean re
clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
fclean:	clean
	rm -f $(NAME)
re:
	@$(MAKE) $(MFLAGS) fclean
	@$(MAKE) $(MFLAGS) all
