FILES := main.c \
		 actions.c \
		 parser.c \
		 stack.c

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
LIBFTPRINTF_DIR := ft_printf

NAMELIBFT := ft
NAMELIBFTPRINTF := ftprintf

.PHONY: all
all: $(NAME)

$(NAME): $(LIBFT_DIR)/lib$(NAMELIBFT).a $(LIBFTPRINTF_DIR)/lib$(NAMELIBFTPRINTF).a $(OBJ)
	$(CC) $(CFLAGS) $(GDB) $(OBJ) -L $(LIBFT_DIR) -L $(LIBFTPRINTF_DIR) -l $(NAMELIBFTPRINTF) -l $(NAMELIBFT) -o $@

$(LIBFT_DIR)/lib$(NAMELIBFT).a:
	make -C $(LIBFT_DIR) bonus

$(LIBFTPRINTF_DIR)/lib$(NAMELIBFTPRINTF).a:
	make -C $(LIBFTPRINTF_DIR) bonus

$(BUILDDIR)/%.o: $(SRCDIR)/%.c Makefile
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c $< -o $@

.PHONY: clean fclean re norm
clean:
	rm -rf $(OBJ)
	make -C $(LIBFT_DIR) clean
	make -C $(LIBFTPRINTF_DIR) clean

fclean: clean
	rm -rf $(NAME)
	make -C $(LIBFT_DIR) fclean
	make -C $(LIBFTPRINTF_DIR) fclean

re : fclean all

norm:
	make -C $(LIBFT_DIR) norm
	make -C $(LIBFTPRINTF_DIR) norm
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine $(INCDIR)/
