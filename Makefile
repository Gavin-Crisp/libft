NAME				:= libft.a

export ROOT			:= $(shell pwd)
export BUILD_DIR	:= $(ROOT)/.build

COMPONENTS			:= \
	allocator binary_tree char converters \
	doubly_linked_list linked_list memory string
COMP_CHECKS			:= $(patsubst %,$(BUILD_DIR)/%/.finished_comp,$(COMPONENTS))

export CC			?= cc
export CFLAGS		?= -Wall -Werror -Wextra

AR					= ar
ARFLAGS				= -rcs

MAKEFLAGS			+= --no-print-directory

ifndef INDENT
	export INDENT	:= 0
else
	export INDENT	:= $(shell echo $$(($(INDENT) + 1)))
endif
export INDENT_STYLE	?= "    "

define print
	for (( i=0; i<$(INDENT); i+=1 ))
	do
		echo $1
	done
endef

all: $(NAME)

$(NAME): $(COMP_CHECKS)
	$(AR) $(ARFLAGS) $@ $(wildcard $(BUILD_DIR)/**/*.o)
	$(eval $(call print,CREATED $@))

$(BUILD_DIR)/%/.finished_comp:
	$(MAKE) -C $*

clean:
	$(eval $(call print,Cleaning libft...))
	for f in $(COMPONENTS); do $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	$(eval $(call print,Done))

fclean:
	$(eval $(call print,Fully cleaning libft...))
	for f in $(COMPONENTS); do $(MAKE) -C $$f clean; done
	rm -rf $(BUILD_DIR)
	rm -fv $(NAME)
	$(eval $(call print,Done))

re:
	$(MAKE) fclean
	$(MAKE) all

norm: ; norminette | grep -v OK || echo "All good"

.PHONY: all clean fclean re norm
.SILENT:
