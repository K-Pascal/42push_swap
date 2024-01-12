FILES := ft_printf.c \
		 ft_printfparser.c \
		 ft_printfutils.c \
		 ft_printfints.c \
		 ft_printfchars.c \
		 ft_printfptr.c \
		 ft_printfint.c \
		 ft_printfuint.c \
		 ft_printfhex.c

SRCDIR := src
INCLUDEDIR := include
BUILDDIR := build
SRC := $(addprefix $(SRCDIR)/,$(FILES))
OBJ := $(addprefix $(BUILDDIR)/,$(FILES:.c=.o))

LIBFTPATH := ./libft

CC := cc
CFLAGS := -Wall -Wextra -Werror
GDB := 

NAME := libftprintf.a
LIBFT := $(LIBFTPATH)/libft.a

.PHONY: all clean fclean re
all:  $(NAME)

clean:
	rm -f $(OBJ)
	$(MAKE) -C $(LIBFTPATH) clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C $(LIBFTPATH) fclean

re: fclean all

$(NAME): $(OBJ) $(LIBFT)
	ar rcs $(NAME) $(OBJ) $(LIBFTOBJ)

$(LIBFT):
	$(MAKE) -C $(LIBFTPATH) bonus
	cp $@ $(NAME)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c -I. -I$(INCLUDEDIR) $< -o $@

.PHONY: bonus
bonus: all

.PHONY: norm
norm:
	make -C $(LIBFTPATH) norm
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine $(INCLUDEDIR)/
