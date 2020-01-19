# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:48:38 by cdai              #+#    #+#              #
#    Updated: 2020/01/19 17:28:24 by cdai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	\
			ft_memset.c\
			ft_bzero.c\
			ft_memcpy.c\
			ft_strlen.c\
			ft_substr.c\
			ft_strdup.c\
			ft_isdigit.c\
			ft_isalpha.c\
			ft_isalnum.c\
			ft_isascii.c\
			ft_isprint.c\
			ft_toupper.c\
			ft_tolower.c\
			ft_atoi.c\
			ft_strncmp.c\
			ft_strnstr.c\
			ft_strrchr.c\
			ft_strchr.c\
			ft_strlcat.c\
			ft_strlcpy.c\
			ft_memccpy.c\
			ft_memmove.c\
			ft_putchar_fd.c\
			ft_putstr_fd.c\
			ft_putendl_fd.c\
			ft_putnbr_fd.c\
			ft_memcmp.c\
			ft_strjoin.c\
			ft_calloc.c\
			ft_split.c\
			ft_itoa.c\
			ft_strtrim.c\
			ft_memchr.c\
			ft_strmapi.c\
			ft_lstnew.c\
			ft_lstadd_front.c\
			ft_lstsize.c\
			ft_lstlast.c\
			ft_lstadd_back.c\
			ft_lstdelone.c\
			ft_lstclear.c\
			ft_lstiter.c\
			ft_lstmap.c\
			get_next_line.c\
			get_next_line_utils.c\
			ft_charchr.c\

OBJS	=	${SRCS:.c=.o}

NAME	=	libft.a

CFLAGS	=	-o -Wall -Wextra -Werror

CC		=	gcc
RM		=	rm -f
AR		=	ar rc
RANLIB	=	ranlib


.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}: ${OBJS}
		${AR} ${NAME} ${OBJS}
		${RANLIB} ${NAME}

all:	${NAME}

clean:
		${RM} ${OBJS}

fclean:	clean
		${RM} ${NAME}

re:		fclean all

norm:
		norminette -R CheckForbiddenSourceHeader *.c *.h

commit:
		git add -A && git commit

.PHONY : all clean fclean re norm commit
