ifndef BUILD_DIR
BUILD_DIR			:= .build
else
BUILD_DIR			:= $(BUILD_DIR)/$(NAME)
endif
OBJS				:= $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SRCS))
DEPS				:= $(patsubst %.o,%.d,$(OBJS))

CC					?= cc
CFLAGS				?= -Wall -Wextra -Werror

ifndef INDENT
	export INDENT	:= 0
else
	export INDENT	:= $(shell echo $$(($(INDENT) + 1)))
endif
export INDENT_STYLE	?= "    "

define print
	for (( i=0; i<$(INDENT); i+=1 ))
	do
		echo $1
	done
endef

all: .finished_comp

.finished_comp: $(OBJS)
	touch $(BUILD_DIR)/.finished_comp

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	mkdir -p $(@D)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c $< -o $@
	$(eval $(call print,CREATED $(@F)))

-include $(DEPS)

clean:
	for f in $(OBJS); \
	do \
		if [ -f $$f ]; \
		then \
			rm $$f || continue; \
			$(eval $(call print,"REMOVED $$(basename $$f)")); \
		fi; \
	done
	rm -rf $(BUILD_DIR)

re:
	$(MAKE) clean
	$(MAKE) all

.PHONY: all clean re
.SILENT:
