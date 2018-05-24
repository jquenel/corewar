CC := cc
CFLAGS := -Wall -Wextra -Werror -MMD -MP
CPPFLAGS := -Iincludes

NAME := libft.a

SRCS_ARRAY := \
	ft_array_create.c ft_array_length.c ft_array_iter.c \
	ft_array_iter_ptr_item.c ft_array_delete.c
SRCS_STR := \
	ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
	ft_islower.c ft_isprint.c ft_isspace.c ft_isupper.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memcpy.c ft_memjoin.c ft_memmove.c ft_memset.c \
	ft_stpcpy.c ft_stpncpy.c ft_strcat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
	ft_strcpy.c ft_strdup.c ft_strequ.c ft_striter.c ft_striteri.c \
	ft_strjoin.c ft_strlcat.c ft_strlen.c ft_wcslen.c ft_strmap.c ft_strmapi.c \
	ft_strncat.c ft_strncmp.c ft_strncpy.c ft_strnequ.c ft_strnstr.c \
	ft_strrchr.c ft_strsplit.c ft_strstr.c ft_strsub.c ft_strtrim.c \
	ft_tolower.c ft_toupper.c kmp.c ft_strnlen.c ft_wcsmbnlen.c \
	ft_split_string.c ft_strforall.c ft_strisstr.c
SRCS_STD := \
	ft_atoi.c ft_atoi_base.c ft_itoa.c ft_wctomb.c ft_min.c ft_max.c \
	ft_int_of_string.c ft_int_of_string_base.c ft_string_of_int.c ft_abs.c \
	ft_htonl.c ft_htons.c ft_ntohl.c ft_ntohs.c
SRCS_IO := \
	ft_putchar.c ft_putchar_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
	ft_putnbr_fd.c ft_putstr.c ft_putstr_fd.c get_next_line.c \
	get_next_line_aux.c
SRCS_LIST := \
	ft_list_length.c ft_list_at.c ft_list_last.c ft_list_insert_after.c \
	ft_list_insert_before.c ft_list_accumulate.c ft_list_remove.c \
	ft_list_clear.c ft_list_find.c ft_list_foreach.c ft_list_merge.c \
	ft_list_reverse.c ft_list_sort.c ft_list_merge_sorted.c
SRCS_HASHTABLE := \
	ft_hash_comp_functions.c ft_hashtable_find.c ft_hashtable_insert.c \
	ft_hashtable_make.c ft_hashtable_remove.c hashtable.c ft_hashtable_iter.c \
	ft_hashtable_destroy.c

SRCS_DIR := srcs
SRCS := \
	$(addprefix $(SRCS_DIR)/array/, $(SRCS_ARRAY)) \
	$(addprefix $(SRCS_DIR)/str/, $(SRCS_STR)) \
	$(addprefix $(SRCS_DIR)/std/, $(SRCS_STD)) \
	$(addprefix $(SRCS_DIR)/io/, $(SRCS_IO)) \
	$(addprefix $(SRCS_DIR)/list/, $(SRCS_LIST)) \
	$(addprefix $(SRCS_DIR)/hashtable/, $(SRCS_HASHTABLE))
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
