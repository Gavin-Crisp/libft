export NAME		:= allocator

export SRC_DIR	:= srcs
SRCS			:= chunk ft_free ft_malloc ft_realloc heap
export SRCS		:= $(patsubst %,$(SRC_DIR)/%.c,$(SRCS))

export CPPFLAGS	:= $(addprefix -I ,$(ROOT) $(ROOT)/$(NAME)/include) -MMD -MP

all:
	$(MAKE) -C $(ROOT) -f component.mk

clean:
	$(MAKE) -C $(ROOT) -f component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
