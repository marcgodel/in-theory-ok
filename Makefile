# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mgodel <marvin@42lausanne.ch>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 12:46:59 by mgodel            #+#    #+#              #
#    Updated: 2023/11/02 10:37:01 by mgodel           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #
NAME = libft.a

all:	$(NAME)

CC = gcc

CFLAGS = -Wall -Wextra -Werror

HEADERS = libft.h

SRCS = ft_isalpha.c \
	   ft_isdigit.c \
	   ft_isalnum.c \
	   ft_isascii.c \
	   ft_isprint.c \
	   ft_strlen.c \
	   ft_memset.c \
	   ft_bzero.c \
	   ft_memcpy.c \
	   ft_memmove.c \
	   ft_strlcpy.c \
	   ft_strlcat.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strchr.c \
	   ft_strrchr.c \
	   ft_strncmp.c \
	   ft_memchr.c \
	   ft_memcmp.c \
	   ft_strnstr.c \
	   ft_atoi.c \
	   ft_calloc.c \
	   ft_strdup.c \
	   ft_substr.c \
	   ft_strjoin.c \
	   ft_strtrim.c \
	   ft_split.c \
	   ft_itoa.c \
	   ft_strmapi.c \
	   ft_striteri.c \
	   ft_putchar_fd.c \
	   ft_putstr_fd.c \
	   ft_putendl_fd.c \
	   ft_putnbr_fd.c


OBJS = $(SRCS:.c=.o)

OBJS : $(SRCS)
	$(CC) $(CFLAGS) -c $^ $@

$(NAME): $(OBJS) $(HEADERS)
	ar -rc $@ $^

SRCS_BONUS =	ft_lstnew_bonus.c \
		ft_lstadd_front_bonus.c \
		ft_lstsize_bonus.c \
		ft_lstlast_bonus.c \
		ft_lstadd_back_bonus.c \
		ft_lstdelone_bonus.c \
		ft_lstclear_bonus.c \
		ft_lstiter_bonus.c \
		ft_lstmap_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

OBJS_BONUS : $(SRCS_BONUS)
	$(CC) $(CFLAGS) -c $^ $@

bonus: $(OBJS_BONUS) $(OBJS) $(HEADERS)
	ar -rc $(NAME) $^

main.o :
	$(CC) -w -c main.c

prog : $(OBJS) main.o
	$(CC) $^ -o $@

RM = rm -f

clean:
	$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: clean fclean re all prog
