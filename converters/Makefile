export NAME		:= $(notdir $(shell pwd))

SRC_DIR			:= .
SRCS			:= \
	atod atoi atol itoa_base \
	itoa uitoa_base uitoa ultoa_base \
	ultoa
export SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

export CPPFLAGS	:= -I $(ROOT) -MMD -MP

all:
	$(MAKE) -f $(ROOT)/component.mk

clean:
	$(MAKE) -f $(ROOT)/component.mk clean

re: clean all

.PHONY: all clean re
.SILENT:
