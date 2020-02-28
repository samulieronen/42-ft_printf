# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: seronen <seronen@student.hive.fi>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/21 12:12:13 by seronen           #+#    #+#              #
#    Updated: 2020/02/28 15:17:59 by seronen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

INCLUDES = libft/includes/

SRC = libft/srcs/ft_isprint.c libft/srcs/ft_memalloc.c libft/srcs/ft_putchar.c libft/srcs/ft_strcat.c libft/srcs/ft_striter.c \
libft/srcs/ft_strncmp.c libft/srcs/ft_strsub.c libft/srcs/ft_itoa.c libft/srcs/ft_memccpy.c libft/srcs/ft_putchar_fd.c libft/srcs/ft_strchr.c \
libft/srcs/ft_striteri.c libft/srcs/ft_strncpy.c libft/srcs/ft_strtrim.c libft/srcs/ft_atoi.c libft/srcs/ft_lstadd.c libft/srcs/ft_memchr.c \
libft/srcs/ft_putendl.c libft/srcs/ft_strclr.c libft/srcs/ft_strjoin.c libft/srcs/ft_strnequ.c libft/srcs/ft_tolower.c libft/srcs/ft_bzero.c \
libft/srcs/ft_lstdel.c libft/srcs/ft_memcmp.c libft/srcs/ft_putendl_fd.c libft/srcs/ft_strcmp.c libft/srcs/ft_strlcat.c libft/srcs/ft_strnew.c \
libft/srcs/ft_toupper.c libft/srcs/ft_isalnum.c libft/srcs/ft_lstdelone.c libft/srcs/ft_memcpy.c libft/srcs/ft_putnbr.c libft/srcs/ft_strcpy.c \
libft/srcs/ft_strlen.c libft/srcs/ft_strnstr.c libft/srcs/ft_isalpha.c libft/srcs/ft_lstiter.c libft/srcs/ft_memdel.c libft/srcs/ft_putnbr_fd.c \
libft/srcs/ft_strdel.c libft/srcs/ft_strmap.c libft/srcs/ft_strrchr.c libft/srcs/ft_isascii.c libft/srcs/ft_lstmap.c libft/srcs/ft_memmove.c \
libft/srcs/ft_putstr.c libft/srcs/ft_strdup.c libft/srcs/ft_strmapi.c libft/srcs/ft_strsplit.c libft/srcs/ft_isdigit.c libft/srcs/ft_lstnew.c \
libft/srcs/ft_memset.c libft/srcs/ft_putstr_fd.c libft/srcs/ft_strequ.c libft/srcs/ft_strncat.c libft/srcs/ft_strstr.c libft/srcs/ft_number_len.c \
libft/srcs/ft_word_ccount.c libft/srcs/ft_word_len_ic.c libft/srcs/get_next_line.c libft/srcs/ft_strndup.c libft/srcs/ft_itoa_base.c libft/srcs/ft_ftoa.c \
libft/srcs/ft_strrev.c libft/srcs/ft_printf/print_char.c libft/srcs/ft_printf/print_dec.c libft/srcs/ft_printf/print_float.c libft/srcs/ft_printf/print_hex.c \
libft/srcs/ft_printf/print_octal.c libft/srcs/ft_printf/print_percentage.c libft/srcs/ft_printf/print_ptr.c libft/srcs/ft_printf/print_str.c \
libft/srcs/ft_printf/print_unsig.c libft/srcs/ft_printf/helpers.c libft/srcs/ft_printf/helpers2.c libft/srcs/ft_printf/ft_printf.c \
libft/srcs/ft_printf/save.c

OBJ = ft_isprint.o ft_memalloc.o ft_putchar.o ft_strcat.o ft_striter.o ft_strncmp.o \
ft_strsub.o ft_itoa.o ft_memccpy.o ft_putchar_fd.o ft_strchr.o ft_striteri.o \
ft_strncpy.o ft_strtrim.o ft_atoi.o ft_lstadd.o ft_memchr.o ft_putendl.o ft_strclr.o \
ft_strjoin.o ft_strnequ.o ft_tolower.o ft_bzero.o ft_lstdel.o ft_memcmp.o ft_putendl_fd.o \
ft_strcmp.o ft_strlcat.o ft_strnew.o ft_toupper.o ft_isalnum.o ft_lstdelone.o ft_memcpy.o \
ft_putnbr.o ft_strcpy.o ft_strlen.o ft_strnstr.o ft_isalpha.o ft_lstiter.o ft_memdel.o \
ft_putnbr_fd.o ft_strdel.o ft_strmap.o ft_strrchr.o ft_isascii.o ft_lstmap.o ft_memmove.o \
ft_putstr.o ft_strdup.o ft_strmapi.o ft_strsplit.o ft_isdigit.o ft_lstnew.o ft_memset.o \
ft_putstr_fd.o ft_strequ.o ft_strncat.o ft_strstr.o ft_number_len.o ft_word_ccount.o \
ft_word_len_ic.o get_next_line.o ft_strndup.o ft_itoa_base.o ft_ftoa.o helpers.o \
helpers2.o save.o ft_printf.o print_char.o print_str.o print_ptr.o print_float.o \
print_hex.o print_unsig.o print_octal.o print_dec.o print_percentage.o ft_strrev.o

all: $(NAME)

$(NAME):
	@gcc -c $(SRC) -Wall -Wextra -Werror -I $(INCLUDES)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

clean:
	@/bin/rm -f $(OBJ)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
