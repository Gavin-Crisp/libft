NAME		:= $(notdir $(shell pwd))

SRC_DIR		:= .
SRCS		:= \
	isalnum isalpha isascii isdigit \
	isprint isspace tolower toupper
SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

ifndef OBJ_DIR
	_OBJ_DIR = .objs
else
	_OBJ_DIR = $(OBJ_DIR)/$(NAME)
endif
OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(_OBJ_DIR)/%.o,$(SRCS))
ifndef DEP_DIR
	_DEP_DIR = .deps
else
	_DEP_DIR = $(DEP_DIR)/$(NAME)
endif
DEPS		:= $(patsubst $(SRC_DIR)/%.c,$(_DEP_DIR)/%.d,$(SRCS))

CC			?= cc
CFLAGS		?= -Wall -Wextra -Werror
CPPFLAGS	= -I $(ROOT) -MT $@ -MMD -MP -MF $(_DEP_DIR)/$*.d

all: $(OBJS)

$(_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	mkdir -p $(dir $(_DEP_DIR)/$*.d)
	$(CC) $(CFLAGS) $(CPPFLAGS)
	echo CREATED $(@F)

-include $(DEPS)

clean:
	for f in $(OBJS); rm -f $$f; echo REMOVED $(notdir $$f); done
	rm -rf $(_OBJ_DIR) $(_DEP_DIR)

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re
.SILENT:
