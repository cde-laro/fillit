# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aancel <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/20 12:39:36 by aancel            #+#    #+#              #
#    Updated: 2016/11/27 14:29:57 by cde-laro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CFLAGS = -Wall -Werror -Wextra -I libft.h

SRC = srcs/libft.a \
	  srcs/main.c \
	  srcs/extract.c \
	  srcs/check_pieces.c \
	  srcs/make_list.c \
	  srcs/test_piece.c \
	  srcs/test_square.c

LIBSRC = srcs/lib/ft_atoi.c \
		 srcs/lib/ft_bzero.c \
		 srcs/lib/ft_count_space.c \
		 srcs/lib/ft_count_word.c \
		 srcs/lib/ft_isalnum.c \
		 srcs/lib/ft_isalpha.c \
		 srcs/lib/ft_isascii.c \
		 srcs/lib/ft_isdigit.c \
		 srcs/lib/ft_isprint.c \
		 srcs/lib/ft_itoa.c \
		 srcs/lib/ft_lstadd.c \
		 srcs/lib/ft_lstdel.c \
		 srcs/lib/ft_lstdelone.c \
		 srcs/lib/ft_lstiter.c \
		 srcs/lib/ft_lstmap.c \
		 srcs/lib/ft_lstnew.c \
		 srcs/lib/ft_memalloc.c \
		 srcs/lib/ft_memccpy.c \
		 srcs/lib/ft_memchr.c \
		 srcs/lib/ft_memcmp.c \
		 srcs/lib/ft_memcpy.c \
		 srcs/lib/ft_memdel.c \
		 srcs/lib/ft_memmove.c \
		 srcs/lib/ft_memset.c \
		 srcs/lib/ft_putchar.c \
		 srcs/lib/ft_putchar_fd.c \
		 srcs/lib/ft_putendl.c \
		 srcs/lib/ft_putendl_fd.c \
		 srcs/lib/ft_putnbr.c \
		 srcs/lib/ft_putnbr_fd.c \
		 srcs/lib/ft_putstr.c \
		 srcs/lib/ft_putstr_fd.c \
		 srcs/lib/ft_strcat.c \
		 srcs/lib/ft_strchr.c \
		 srcs/lib/ft_strclr.c \
		 srcs/lib/ft_strcmp.c \
		 srcs/lib/ft_strcpy.c \
		 srcs/lib/ft_strdel.c \
		 srcs/lib/ft_strdup.c \
		 srcs/lib/ft_strequ.c \
		 srcs/lib/ft_striter.c \
		 srcs/lib/ft_striteri.c \
		 srcs/lib/ft_strjoin.c \
		 srcs/lib/ft_strlcat.c \
		 srcs/lib/ft_strlen.c \
		 srcs/lib/ft_strmap.c \
		 srcs/lib/ft_strmapi.c \
		 srcs/lib/ft_strncat.c \
		 srcs/lib/ft_strncmp.c \
		 srcs/lib/ft_strncpy.c \
		 srcs/lib/ft_strnequ.c \
		 srcs/lib/ft_strnew.c \
		 srcs/lib/ft_strnstr.c \
		 srcs/lib/ft_strrchr.c \
		 srcs/lib/ft_strrev.c \
		 srcs/lib/ft_strsplit.c \
		 srcs/lib/ft_strstr.c \
		 srcs/lib/ft_strsub.c \
		 srcs/lib/ft_strtrim.c \
		 srcs/lib/ft_tolower.c \
		 srcs/lib/ft_toupper.c \
		 srcs/lib/ft_puttab.c \
		 srcs/lib/ft_puttab_fd.c \
		 srcs/lib/ft_create_tab.c

OBJ = ft_atoi.o \
	  ft_bzero.o \
	  ft_count_space.o \
	  ft_count_word.o \
	  ft_isalnum.o \
	  ft_isalpha.o \
	  ft_isascii.o \
	  ft_isdigit.o \
	  ft_isprint.o \
	  ft_itoa.o \
	  ft_lstadd.o \
	  ft_lstdel.o \
	  ft_lstdelone.o \
	  ft_lstiter.o \
	  ft_lstmap.o \
	  ft_lstnew.o \
	  ft_memalloc.o \
	  ft_memccpy.o \
	  ft_memchr.o \
	  ft_memcmp.o \
	  ft_memcpy.o \
	  ft_memdel.o \
	  ft_memmove.o \
	  ft_memset.o \
	  ft_putchar.o \
	  ft_putchar_fd.o \
	  ft_putendl.o \
	  ft_putendl_fd.o \
	  ft_putnbr.o \
	  ft_putnbr_fd.o \
	  ft_putstr.o \
	  ft_putstr_fd.o \
	  ft_strcat.o \
	  ft_strchr.o \
	  ft_strclr.o \
	  ft_strcmp.o \
	  ft_strcpy.o \
	  ft_strdel.o \
	  ft_strdup.o \
	  ft_strequ.o \
	  ft_striter.o \
	  ft_striteri.o \
	  ft_strjoin.o \
	  ft_strlcat.o \
	  ft_strlen.o \
	  ft_strmap.o \
	  ft_strmapi.o \
	  ft_strncat.o \
	  ft_strncmp.o \
	  ft_strncpy.o \
	  ft_strnequ.o \
	  ft_strnew.o \
	  ft_strnstr.o \
	  ft_strrchr.o \
	  ft_strrev.o \
	  ft_strsplit.o \
	  ft_strstr.o \
	  ft_strsub.o \
	  ft_strtrim.o \
	  ft_tolower.o \
	  ft_toupper.o \
	  ft_puttab.o \
	  ft_puttab_fd.o \
	  ft_create_tab.o

LIBNAME = srcs/libft.a

all: $(NAME)

$(NAME): $(LIBNAME)
	@gcc $(CFLAGS) $(SRC) -o $(NAME)
	@echo "\\0033[32mExecutable created\\0033[0m"

$(LIBNAME):
	@gcc -c $(CFLAGS) $(LIBSRC)
	@ar rc $(LIBNAME) $(OBJ)
	@ranlib $(LIBNAME)


clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME) $(LIBNAME)
	@echo "\\0033[31mExecutable deleted\\0033[0m"

re: fclean all
