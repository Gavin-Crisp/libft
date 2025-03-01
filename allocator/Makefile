export NAME		:= allocator

SRC_DIR			:= srcs
SRCS			:= ft_free ft_malloc ft_realloc util
export SRCS		:= $(patsubst %,$(SRC_DIR)/%.c,$(SRCS))

export CPPFLAGS	:= $(addprefix -I ,$(ROOT) include) -MMD -MP

all:
	$(MAKE) -f $(ROOT)/component.mk

clean:
	$(MAKE) -f $(ROOT)/component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
