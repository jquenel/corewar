CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -I../libft/includes

NAME := libftprintf.a

SRCS := \
	aux.c buffer.c buffer_put.c char_str_conv.c format.c format_conv_aux.c \
	float_conv.c ft_printf.c integer_conv.c other_conv.c padding.c read_arg.c
OBJS := $(SRCS:.c=.o)
DEPS := $(SRCS:.c=.d)

.PHONY:	all
all:	$(NAME)

-include $(DEPS)

$(NAME):	$(OBJS)
	ar ru $@ $^

.PHONY:	clean fclean re
clean:
	rm -f $(OBJS)
	rm -f $(DEPS)
fclean:	clean
	rm -f $(NAME)
re:
	@$(MAKE) $(MFLAGS) fclean
	@$(MAKE) $(MFLAGS) all
