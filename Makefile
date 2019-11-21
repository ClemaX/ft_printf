NAME	= libftprintf.a
LIBFT	= libft
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
HEADER	= libftprintf.h
OBJDIR	= obj
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR)
LFLAGS	= -L$(LIBFT)
SRCS	= $(addprefix $(SRCDIR)/, ft_printf.c strings.c ft_numbers.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
TEST	= tests/main.c

all:			$(NAME)

$(NAME):		$(OBJDIR) $(OBJS) $(INCDIR)/$(HEADER)
	ar rcus $(NAME) $(OBJS)

$(OBJDIR):
	mkdir -p $(OBJDIR)

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -c -o $@ $<

clean:
	/bin/rm -rf $(OBJDIR)

fclean: 		clean
	/bin/rm -f $(NAME)

re: fclean all
