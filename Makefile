# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: akasiota <akasiota@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2026/05/21 14:52:57 by akasiota      #+#    #+#                  #
#    Updated: 2026/06/18 17:10:29 by akasiota      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME := libasm.a

TESTMAIN := test.out

ASM := nasm
CC := cc

ASMFLAGS := -f elf64 #-w+all
CCFLAGS := -Wall -Wextra -Werror -I.

LIBSRCDIR := src/lib
TESTSRCDIR := src/test
LIBOBJDIR := obj/lib
TESTOBJDIR := obj/test

LIBSRCFILES := ft_read.s \
			ft_strcmp.s \
			ft_strcpy.s \
			ft_strdup.s \
			ft_strlen.s \
			ft_write.s
TESTSRCFILE := $(TESTSRCDIR)/test.c

LIBOBJFILES := $(addprefix $(LIBOBJDIR)/, $(LIBSRCFILES:.s=.o))
TESTOBJFILE := $(TESTOBJDIR)/test.o

all: $(NAME) $(TESTMAIN)

$(NAME): $(LIBOBJDIR) $(LIBOBJFILES)
	ar -rcs $@ $^

$(LIBOBJDIR):
	mkdir -p $(LIBOBJDIR)

$(TESTOBJDIR):
	mkdir -p $(TESTOBJDIR)

$(TESTMAIN): $(TESTOBJFILE) $(NAME)
	$(CC) $(CCFLAGS) $^ -o $@

$(LIBOBJDIR)/%.o: $(LIBSRCDIR)/%.s | $(LIBOBJDIR)
	$(ASM) $(ASMFLAGS) $< -o $@

$(TESTOBJFILE): $(TESTOBJDIR) $(TESTSRCFILE) | $(TESTOBJDIR)
	$(CC) -c $(CCFLAGS) $< -o $@

clean:
	rm -f $(TESTOBJFILE)
	rm -f $(LIBOBJFILES)

fclean: clean
	rm -f $(TESTMAIN)
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re