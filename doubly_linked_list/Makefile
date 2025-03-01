export NAME		:= $(notdir $(shell pwd))

SRC_DIR			:= .
SRCS			:= \
	add_front clear cmp find \
	find_closest first add_back index_after \
	index_before insert_after insert_before is_sorted \
	iter last match new \
	remove_elem remove_after remove_before size
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -f $(ROOT)/component.mk

clean:
	$(MAKE) -f $(ROOT)/component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
