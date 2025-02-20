NAME = $(patsubst %, lib%.a, $(notdir $(shell pwd)))

SRCS = $(shell find $(SDIR) -name "*.c")
OBJS = $(patsubst $(SDIR)/%.c, $(ODIR)/%.o, $(SRCS))

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	@echo "Creating library $@ from objects..."
	@ar -rcs $@ $^
	@echo "Done!"

$(ODIR)/%.o: $(SDIR)/%.c
	@echo "Compiling $(<F) to object..."
	@mkdir -p $(@D)
	@$(CC) $(CFLAGS) $(DFLAGS) $(addprefix -I, $(HDIR)) -o $@ -c $<

clean:
	@echo "Cleaning $(NAME)..."
	@rm -fv $(OBJS)
	@echo "Done!"

fclean:
	@echo "Fully cleaning $(NAME)..."
	@rm -fv $(OBJS) $(NAME)
	@echo "Done!"

re: fclean all
