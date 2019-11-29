NAME	= libftprintf.a
LIBFT	= libft
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
OBJDIR	= objs
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT)
SRCS	= $(addprefix $(SRCDIR)/, ft_printf.c specs.c format.c line.c numbers.c convert.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))
HDRS	= $(addprefix $(INCDIR)/, libftprintf.h format.h line.h numbers.h specs.h)

all:			libft $(NAME)

libft:
	make -C $(LIBFT) NAME=libft.a

$(LIBFT)/libft.a: libft

$(NAME):	 	$(LIBFT)/libft.a $(OBJDIR) $(OBJS)
	cp $(LIBFT)/libft.a $(NAME)
	ar rcus $@ $(OBJS)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c $(HDRS)
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFT) $@ NAME=libft.a
	/bin/rm -rf $(OBJDIR)

fclean: 		clean
	make -C $(LIBFT) $@ NAME=libft.a
	/bin/rm -f $(NAME)

re: fclean all

bonus:		$(NAME)

.PHONY: libft
