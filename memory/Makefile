export NAME		:= $(notdir $(shell pwd))

SRC_DIR			:= .
SRCS			:= \
	bzero calloc memchr memcmp \
	memcpy memmove memset memswap
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -f $(ROOT)/component.mk

clean:
	$(MAKE) -f $(ROOT)/component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
