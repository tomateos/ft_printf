# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tzhou <tzhou@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/28 11:45:49 by tzhou             #+#    #+#              #
#    Updated: 2017/05/15 14:58:12 by tzhou            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

WFLAG = -Wall -Werror -Wextra
CC = gcc
INC = -I includes

SDIR = src
ODIR = obj

SRC = ft_memset.c ft_bzero.c ft_memcpy.c ft_memccpy.c ft_memmove.c ft_memchr.c \
	  ft_memcmp.c ft_strlen.c ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strcat.c \
	  ft_strncat.c ft_strlcat.c ft_strchr.c ft_strrchr.c ft_strstr.c \
	  ft_strnstr.c ft_strcmp.c ft_strncmp.c ft_atoi.c ft_isalpha.c \
	  ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_toupper.c \
	  ft_tolower.c ft_memalloc.c ft_memdel.c ft_strnew.c ft_strdel.c \
	  ft_strclr.c ft_striter.c ft_striteri.c ft_strmap.c ft_strmapi.c \
	  ft_strequ.c ft_strnequ.c ft_strsub.c ft_strjoin.c ft_strtrim.c \
	  ft_strsplit.c ft_itoa.c ft_putchar.c ft_putstr.c ft_putendl.c \
	  ft_putnbr.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	  ft_putnbr_fd.c ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c \
	  ft_lstiter.c ft_lstmap.c ft_itoa_base.c ft_putnchar.c ft_print_memory.c \
	  ft_isupper.c ft_islower.c ft_memlocate.c ft_strlocate.c ft_strndup.c \
	  get_next_line.c

OBJ = ${SRC:.c=.o}

SRCS = $(addprefix $(SDIR)/, $(SRC))
OBJS = $(addprefix $(ODIR)/, $(OBJ))

all: $(NAME)

$(ODIR)/%.o: $(SDIR)/%.c
	@mkdir -p $(ODIR)
	@$(CC) -c $(WFLAG) $(INC) $< -o $@

$(NAME): $(OBJS)
	@ar rc $@ $^
	@ranlib $@
	@echo "\033[0;32m[libft.a created]\033[0m"

clean:
	@/bin/rm -rf $(ODIR)
	@echo "\033[0;31m[obj/*.o cleaned]\033[0m"

fclean: clean
	@/bin/rm -f $(NAME)
	@echo "\033[0;31m[libft.a cleaned]\033[0m"

re: fclean $(NAME)
