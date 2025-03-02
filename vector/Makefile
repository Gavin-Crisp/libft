export NAME		:= vector

SRC_DIR			:= .
SRCS			:= \
	delete for_each free index \
	insert_elems insert map new_from_array \
	new_from_func new_with_capacity new pop_elems \
	pop push_elems push remove_elems \
	remove reserve
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -f $(ROOT)/component.mk

clean:
	$(MAKE) -f $(ROOT)/component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
