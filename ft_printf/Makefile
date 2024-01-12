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

CC := cc
CFLAGS := -Wall -Wextra -Werror
GDB ?= 

NAME := libftprintf.a

.PHONY: all clean fclean re
all:  $(NAME)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

$(BUILDDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(BUILDDIR)
	$(CC) $(CFLAGS) $(GDB) -c -I . -I $(INCLUDEDIR) $< -o $@

.PHONY: bonus norm
bonus: all

norm:
	norminette -R CheckForbiddenSourceHeader $(SRC)
	norminette -R CheckDefine $(INCLUDEDIR)/
