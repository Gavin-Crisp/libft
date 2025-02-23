NAME				:= libft.a

export ROOT			:= $(shell pwd)
export BUILD_DIR	:= $(ROOT)/.build

COMPONENTS			:= \
	binary_tree char converters doubly_linked_list \
	linked_list memory string

export CC			?= cc
export CFLAGS		?= -Wall -Werror -Wextra

AR					= ar
ARFLAGS				= -rcs

all: $(NAME)

$(NAME):
	for f in $(COMPONENTS); do $(MAKE) -C $$f; done
	$(AR) $(ARFLAGS) $@ $(wildcard $(BUILD_DIR)/**/*.o)
	echo CREATED $@

clean:
	echo Cleaning libft...
	for f in $(COMPONENTS); $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	echo Done

fclean:
	echo Fully cleaning libft...
	for f in $(COMPONENTS); $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR) $(NAME)
	echo REMOVED $(NAME)
	echo Done

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette | grep -v OK

.PHONY: all clean fclean re norm
.SILENT:
