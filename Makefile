NAME			:= libft.a

export ROOT		:= $(shell pwd)

BUILD_DIR		:= $(ROOT)/.build
OBJ_DIR			:= $(BUILD_DIR)/objs
DEP_DIR			:= $(BUILD_DIR)/deps

COMPONENTS		:= \
	binary_tree char converters doubly_linked_list \
	linked_list memory string

export CC		?= cc
export CFLAGS	?= -Wall -Werror -Wextra

AR			= ar
ARFLAGS		= -rcs

all: $(NAME)

$(NAME):
	for f in $(COMPONENTS); do $(MAKE) -C $$f; done
	$(AR) $(ARFLAGS) $@ $(wildcard $(OBJ_DIR))
	echo CREATED $@

clean:
	echo Cleaning libft...
	for f in $(COMPONENTS); $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	echo Done

fclean:
	echo Fully cleaning libft...
	for f in $(COMPONENTS); $(MAKE) -C $$f clean; done
	echo REMOVED $(NAME)
	rm -rf $(BUILD_DIR)
	echo Done

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette | grep -v OK

.PHONY: all clean fclean re norm
.SILENT:
