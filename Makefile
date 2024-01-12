FILES := main.c

SRCDIR := ./src
SRC := $(addprefix $(SRCDIR)/,$(FILES))

BUILDDIR := ./build
OBJ := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))

INCDIR := ./inc

CC := cc
CFLAGS := -Wall -Wextra -Werror -I $(INCDIR) -I .
GDB := -g3

NAME := push_swap

LIBFTDIR := ./ft_printf
NAMELIB := ftprintf
LIBFT := $(LIBFTDIR)/$(addsuffix .a,$(addprefix lib,$(NAMELIB)))

.PHONY: all clean fclean re
all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(CFLAGS) $(GDB) $(OBJ) -L $(LIBFTDIR) -l $(NAMELIB) -o $@

$(LIBFT):
	make -C $(LIBFTDIR) bonus

clean:
	rm -rf $(OBJ)
	make -C $(LIBFTDIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFTDIR) fclean

re : fclean all


$(BUILDDIR)/%.o: $(SRCDIR)/%.c Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c $< -o $@

.PHONY: norm
norm:
	make -C $(LIBFTDIR) norm
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine $(INCDIR)/
