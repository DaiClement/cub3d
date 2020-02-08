# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdai <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/11/04 14:48:38 by cdai              #+#    #+#              #
#    Updated: 2020/02/08 19:24:02 by cdai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES	=	\
				./includes/cub3d.h\
				./includes/cub3d_struct.h\
				./libft/libft.h\
				./libft/get_next_line.h\

LIBFT_PATH	=	./libft/

LIBFT_SRCS	=	\
				${LIBFT_PATH}ft_memset.c\
				${LIBFT_PATH}ft_bzero.c\
				${LIBFT_PATH}ft_memcpy.c\
				${LIBFT_PATH}ft_strlen.c\
				${LIBFT_PATH}ft_substr.c\
				${LIBFT_PATH}ft_strdup.c\
				${LIBFT_PATH}ft_isdigit.c\
				${LIBFT_PATH}ft_isalpha.c\
				${LIBFT_PATH}ft_isalnum.c\
				${LIBFT_PATH}ft_isascii.c\
				${LIBFT_PATH}ft_isprint.c\
				${LIBFT_PATH}ft_toupper.c\
				${LIBFT_PATH}ft_tolower.c\
				${LIBFT_PATH}ft_atoi.c\
				${LIBFT_PATH}ft_strncmp.c\
				${LIBFT_PATH}ft_strnstr.c\
				${LIBFT_PATH}ft_strrchr.c\
				${LIBFT_PATH}ft_strchr.c\
				${LIBFT_PATH}ft_strlcat.c\
				${LIBFT_PATH}ft_strlcpy.c\
				${LIBFT_PATH}ft_memccpy.c\
				${LIBFT_PATH}ft_memmove.c\
				${LIBFT_PATH}ft_putchar_fd.c\
				${LIBFT_PATH}ft_putstr_fd.c\
				${LIBFT_PATH}ft_putendl_fd.c\
				${LIBFT_PATH}ft_putnbr_fd.c\
				${LIBFT_PATH}ft_memcmp.c\
				${LIBFT_PATH}ft_strjoin.c\
				${LIBFT_PATH}ft_calloc.c\
				${LIBFT_PATH}ft_split.c\
				${LIBFT_PATH}ft_itoa.c\
				${LIBFT_PATH}ft_strtrim.c\
				${LIBFT_PATH}ft_memchr.c\
				${LIBFT_PATH}ft_strmapi.c\
				${LIBFT_PATH}ft_lstnew.c\
				${LIBFT_PATH}ft_lstadd_front.c\
				${LIBFT_PATH}ft_lstsize.c\
				${LIBFT_PATH}ft_lstlast.c\
				${LIBFT_PATH}ft_lstadd_back.c\
				${LIBFT_PATH}ft_lstdelone.c\
				${LIBFT_PATH}ft_lstclear.c\
				${LIBFT_PATH}ft_lstiter.c\
				${LIBFT_PATH}ft_lstmap.c\
				${LIBFT_PATH}get_next_line.c\
				${LIBFT_PATH}get_next_line_utils.c\
				${LIBFT_PATH}ft_charchr.c\
				${LIBFT_PATH}ft_dtoi.c\

LIBFT_OBJS	=	${LIBFT_SRCS:.c=.o}

SRCS		=	\
				srcs/ft_check_file_extention.c\
				srcs/cub3d.c\
				srcs/ft_parse_cub.c\
				srcs/ft_launch_game.c\
				srcs/ft_free_all.c\
				srcs/ft_check_scene_element.c\
				srcs/ft_fullfill_resolution.c\
				srcs/ft_fullfill_path.c\
				srcs/ft_fullfill_floor.c\
				srcs/ft_fullfill_ceilling.c\
				srcs/ft_check_atoi_max_min.c\
				srcs/ft_isinrange.c\
				srcs/ft_fullfill_map.c\
				srcs/ft_check_n_parse_map.c\
				srcs/ft_put_map_to_image.c\
				srcs/ft_handle_image.c\
				srcs/ft_handle_keyboard.c\
				srcs/ft_prepare_images.c\
				srcs/ft_handle_mouvement.c\
				srcs/ft_handle_mouvement_utils.c\
				srcs/ft_modulo_two_pi.c\

OBJS		=	${SRCS:.c=.o}

NAME		=	cub3D

GRAPH_FLAGS	=	-lmlx -framework OpenGL -framework AppKit -O3
CFLAGS		=	-o ${FLAGS}
FLAGS		=	-Wall -Wextra -Werror


CC			=	gcc
RM			=	rm -f
AR			=	ar rc

LIBFT		=	libft.a

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}\
				-I${LIBFT_PATH} -I./includes/

${NAME}:		${LIBFT_OBJS} ${OBJS} ${INCLUDES}
				make -C libft
				${CC} -o ${NAME}\
				${FLAGS}\
				${GRAPH_FLAGS}\
				${OBJS}\
				-I${LIBFT_PATH}\
				-I./includes/\
				-L${LIBFT_PATH} -lft\

all:			${NAME}

libft:			${LIBFT_OBJS}
				make -C libft

clean:
				make clean -C libft
				${RM} ${OBJS}

fclean: 
				make fclean -C libft
				${RM} ${OBJS}
				${RM} ${NAME}

re:				fclean all

test:			all
				./${NAME} scene_description/subject.cub

norm:
				#make norm -C ${LIBFT_PATH}
				norminette -R CheckForbiddenSourceHeader srcs includes

leaks:
				leaks ${NAME}

commit:
				git add -A && git commit

.PHONY :		 all clean fclean re norm commit test
