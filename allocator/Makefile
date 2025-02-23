NAME		:= $(notdir $(shell pwd))

SRC_DIR		:= srcs
SRCS		:= \
	ft_free ft_malloc ft_realloc util
SRCS		:= $(patsubst %,$(SRC_DIR)/%.c,$(SRCS))

ifndef BUILD_DIR
_BUILD_DIR	:= .build
else
_BUILD_DIR	:= $(BUILD_DIR)/$(NAME)
endif

OBJS		:= $(patsubst $(SRC_DIR)/%.c,$(_BUILD_DIR)/%.o,$(SRCS))
DEPS		:= $(patsubst %.o,%.d,$(OBJS))

CC			?= cc
CFLAGS		?= -Wall -Wextra -Werror
CPPFLAGS	:= $(addprefix -I ,$(ROOT) include) -MMD -MP

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
