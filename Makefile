# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: atamraka <atamraka@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/09 19:27:33 by atamraka          #+#    #+#              #
#    Updated: 2022/10/10 20:31:16 by atamraka         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

CC = gcc
FLAGS = -c -Wall -Werror -Wextra
INCLUDES = -I ./includes -I ./libft

LIBFT = ./libft

SRCS = ft_printf.c ft_ftoa.c print_utils.c process_length_modifier.c  \
		process_string.c ft_printf.c process_char.c process_numbers.c \
		process_uint.c number_utils.c process_float.c process_octal.c utils.c \
		parse_spec.c process_hex.c process_percentage.c

SRCS_PATH = srcs/
SRCS_FULL_PATH = $(addprefix $(SRCS_PATH), $(SRCS))

LIBFT_OBJ = $(addprefix libft/, ft_atoi.o ft_bzero.o ft_isalnum.o \
			ft_isalpha.o ft_isascii.o ft_isdigit.o ft_isprint.o ft_itoa.o\
			ft_lstadd.o ft_lstdel.o ft_lstdelone.o ft_lstiter.o ft_lstmap.o \
			ft_lstnew.o ft_memalloc.o ft_memccpy.o ft_memchr.o ft_memcmp.o \
			ft_memcpy.o ft_memdel.o ft_memmove.o ft_memset.o ft_putchar.o \
			ft_putchar_fd.o ft_putendl.o ft_putendl_fd.o ft_putnbr.o \
			ft_putnbr_fd.o ft_putstr.o ft_putstr_fd.o ft_strcat.o ft_strchr.o \
			ft_strclr.o ft_strcmp.o	ft_strcpy.o ft_strdel.o ft_strdup.o \
			ft_strequ.o ft_striter.o ft_striteri.o ft_strjoin.o ft_strlcat.o \
			ft_strlen.o ft_strmap.o ft_strmapi.o ft_strncat.o ft_strncmp.o \
			ft_strncpy.o ft_strnequ.o ft_strnew.o ft_strnstr.o ft_strrchr.o\
			ft_strsplit.o ft_strstr.o ft_strsub.o ft_strtrim.o ft_tolower.o\
			ft_toupper.o ft_abs.o ft_div_mod.o ft_lst_delcontent.o \
			ft_strndup.o ft_swap.o)



OBJ = $(SRCS:.c=.o)


all: $(NAME)

$(NAME):
		@make -C $(LIBFT)
		@$(CC) $(FLAGS) $(INCLUDES) $(SRCS_FULL_PATH)
		@ar rc $(NAME) $(OBJ) $(LIBFT_OBJ)

clean:
		@rm -f $(OBJ)
		@make -C $(LIBFT) clean

fclean: clean
		@rm -f $(NAME)
		@make -C $(LIBFT) fclean

re: fclean all
