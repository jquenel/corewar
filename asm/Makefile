CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I../libft/includes -I../ft_printf
LDFLAGS := -L../libft -lft -L../ft_printf -lftprintf

NAME := asm

SRCS := \
	ast.c lexer.c main.c parser.c xmalloc.c
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
