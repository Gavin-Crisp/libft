NAME		:= $(notdir $(shell pwd))

SRC_DIR		:= .
SRCS		:= \
	delete for_each free index \
	insert map new_from_array new_from_func \
	new_with_capacity new pop_first pop_last \
	push_first push_last remove
SRCS		:= $(patsubst %,$(SRC_DIR)/ft_%.c,$(SRCS))

ifndef BUILD_DIR
_BUILD_DIR	:= .build
else
_BUILD_DIR	:= $(BUILD_DIR)/$(NAME)
endif

OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(_BUILD_DIR)/%.o,$(SRCS))
DEPS		:= $(patsubst %.o,%.d,$(OBJS))

CC			?= cc
CFLAGS		?= -Wall -Wextra -Werror
CPPFLAGS	:= -I $(ROOT) -MMD -MP

all: $(OBJS)

$(_BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS)
	echo CREATED $(@F)

-include $(DEPS)

clean:
	for f in $(OBJS); rm -f $$f; echo REMOVED $(notdir $$f); done
	rm -rf $(_BUILD_DIR)

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re
.SILENT:
