FILES := main.c \
		 actions.c \
		 actions_utils.c \
		 parser.c \
		 stack.c \
		 sorts_utils.c \
		 radix_sort.c \
		 small_sort.c \
		 small_sort_utils.c \
		 ranks.c

SRCDIR := ./src
SRC := $(addprefix $(SRCDIR)/,$(FILES))

BUILDDIR := ./build
OBJ := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))

INCDIR := ./inc

CC := cc
CFLAGS := -Wall -Wextra -Werror -I $(INCDIR) -I .
GDB := -g3
export GDB

NAME := push_swap

LIBFT_DIR := libft

NAMELIBFT := ft

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT_DIR)/lib$(NAMELIBFT).a $(OBJ)
	$(CC) $(CFLAGS) $(GDB) $(OBJ) -L $(LIBFT_DIR) -l $(NAMELIBFT) -o $@

$(LIBFT_DIR)/lib$(NAMELIBFT).a:
	make -C $(LIBFT_DIR) bonus

$(BUILDDIR)/%.o: $(SRCDIR)/%.c Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c $< -o $@

.PHONY: clean fclean re norm test
clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean

re : fclean all
	make -C $(LIBFT_DIR) re

norm:
	make -C $(LIBFT_DIR) norm
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine $(INCDIR)/

test: $(NAME)
	cp $(NAME) ./push_swap_visualizer/build/$(NAME)
