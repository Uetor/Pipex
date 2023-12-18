# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedrogon <pedrogon@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/04/30 12:59:07 by pedrogon          #+#    #+#              #
#    Updated: 2023/09/20 21:51:33 by pedrogon         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
ft_isprint.c ft_memcpy.c ft_memmove.c ft_memset.c ft_strchr.c ft_strlcat.c \
ft_strlcpy.c ft_strlen.c ft_toupper.c ft_tolower.c ft_strrchr.c ft_strncmp.c \
ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c \
ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c ft_strmapi.c \
ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
get_next_line.c ft_decimal.c ft_pointer.c ft_unsigned_int.c hexalower.c \
hexauper.c ft_printf.c ft_putchar.c ft_putstr.c

#BONUS = 

OBJS = $(SRC:.c=.o)
BONUES = $(BONUS:.c.o)
CC = gcc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f

$(NAME):
	$(CC) -c $(CFLAGS) $(SRC)
	ar cr $(NAME) $(OBJS)

#bonus:
#	$(CC) -c $(CFLAGS) $(BONUS)
#	ar cr $(NAME) $()
	
all: $(NAME)

clean:
	$(RM) $(OBJS)
fclean: clean	
	$(RM) $(NAME)
re:	fclean	all

.PHONY : all clean fclean re