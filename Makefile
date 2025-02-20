NAME		= ft

SRC_DIR		= srcs
SRCS		+= $(addprefix $(SRC_DIR)/binary_tree/ft_,$(addsuffix .c, balance_factor balance clear height insert_balanced insert is_balanced new rotate_left rotate_right search size))
SRCS		+= $(addprefix $(SRC_DIR)/char/ft_,$(addsuffix .c, isalnum isalpha isascii isdigit isprint isspace tolower toupper))
SRCS		+= $(addprefix $(SRC_DIR)/converters/ft_,$(addsuffix .c, atod atoi atol itoa_base itoa uitoa_base uitoa ultoa_base))
SRCS		+= $(addprefix $(SRC_DIR)/doubly_linked_list/ft_,$(addsuffix .c, add_back add_front clear cmp find first index insert_after insert_before is_sorted iter last match new remove_elem remove size))
SRCS		+= $(addprefix $(SRC_DIR)/linked_list/ft_lst,$(addsuffix .c, add_back add_front clear find index is_sorted iter last map max min new pop remove size split_before split))
SRCS		+= $(addprefix $(SRC_DIR)/memory/ft_,$(addsuffix .c, bzero calloc memchr memcmp memcpy memmove memset))
SRCS		+= $(addprefix $(SRC_DIR)/stack/ft_,$(addsuffix .c, clear new_from_ints new_from_list new pop push rotate_rev rotate swap_top))
SRCS		+= $(addprefix $(SRC_DIR)/string/ft_,$(addsuffix .c, ft_split strchr strchrs strcmp strdup striteri strjoin strlcat strlcpy strlen strmapi strncmp strndup strnstr strrchr strtoupper strtrim substr))

BUILD_DIR	= .build
OBJ_DIR		= $(BUILD_DIR)/objs
OBJS		= $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))
DEP_DIR		= $(BUILD_DIR)/deps
DEPS		= $(patsubst $(SRC_DIR)/%.c,$(DEP_DIR)/%.d,$(SRCS))

CC			?= cc
CFLAGS		?= -Wall -Werror -Wextra
CPPFLAGS	:= -MMD -MP

AR			= ar
ARFLAGS		= -rcs

.PHONY: all clean fclean re norm
.SILENT:

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $@ $^
	$(info CREATED $@)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	mkdir -p $(dir $(DEP_DIR)/$*.d)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $^ -o $@
	$(info CREATED $@)

-include $(DEPS)

clean:
	$(info Cleaning libft...)
	rm -fv $(OBJS) $(DEPS)
	rm -rf $(BUILD_DIR)
	$(info Done)

fclean:
	$(info Fully cleaning libft...)
	rm -fv $(OBJS) $(DEPS) $(NAME)
	rm -rf $(BUILD_DIR)
	$(info Done)

re: fclean all

norm: ; norminette | grep -v OK
