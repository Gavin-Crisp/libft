export NAME		:= $(notdir $(shell pwd))

SRC_DIR		:= srcs
SRCS		:= get_next_line utils
export SRCS		:= $(patsubst %,$(SRC_DIR)/%.c,$(SRCS))

export CPPFLAGS	:= $(addprefix -I ,$(ROOT) include) -MMD -MP

all:
	$(MAKE) -f $(ROOT)/component.mk

clean:
	$(MAKE) -f $(ROOT)/component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
