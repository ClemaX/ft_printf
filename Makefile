NAME	= libftprintf.a
LIBFT	= lib/libft.a
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= include
OBJDIR	= obj
CFLAGS	= -Wall -Wextra -Werror -I$(INCDIR)
SRCS	= $(addprefix $(SRCDIR)/,ft_printf.c, strings.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
TEST	= tests/main.c

all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJS)
	ar rcs $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	/bin/rm -rf $(OBJDIR)

fclean: 		clean
	/bin/rm -f $(NAME)

test:			$(TEST) $(NAME)
	$(CC) $(CFLAGS) $(TEST) $(LIBFT) $(NAME)

re: fclean all
