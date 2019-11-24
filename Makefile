NAME	= libftprintf.a
LIBFT	= libft
CC		= /usr/bin/gcc
SRCDIR	= srcs
INCDIR	= includes
HEADER	= libftprintf.h
OBJDIR	= objs
CFLAGS	= -Wall -Wextra -Werror
IFLAGS	= -I$(INCDIR) -I$(LIBFT)
LFLAGS	= #-L$(LIBFT) -lft
SRCS	= $(addprefix $(SRCDIR)/, ft_printf.c specs.c format.c line.c numbers.c)
OBJS	= $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SRCS))

all:			libft $(NAME)

libft:
	make -C $(LIBFT) libft.a

$(LIBFT)/libft.a: libft

$(NAME):	 	$(LIBFT)/libft.a $(OBJDIR) $(OBJS) $(INCDIR)/$(HEADER)
	cp $(LIBFT)/libft.a libftprintf.a
	ar rcus $@ $(OBJS)

$(OBJDIR):
	mkdir -p $@

$(OBJDIR)/%.o:	$(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(IFLAGS) $(LFLAGS) -c -o $@ $<

clean:
	make -C $(LIBFT) $@
	/bin/rm -rf $(OBJDIR)

fclean: 		clean
	make -C $(LIBFT) $@
	/bin/rm -f $(NAME)

re: fclean all

.PHONY: libft
