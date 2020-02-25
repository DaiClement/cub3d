# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cdai <cdai@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/14 10:52:59 by cdai              #+#    #+#              #
#    Updated: 2020/02/25 15:17:17 by cdai             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

INCLUDES	=	\
				./includes/cub3d.h\
				./includes/cub3d_struct.h\
				./includes/libft.h\
				./includes//get_next_line.h\

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

LIBFT_OBJS	=	${LIBFT_SRCS:.c=.o}

SRCS		=	\
				srcs/main.c\
				srcs/ft_launch_game.c\
				srcs/ft_parse_cub.c\
				srcs/ft_check_file_extention.c\
				srcs/ft_free_gnl_value.c\
				srcs/ft_check_scene_element.c\
				srcs/ft_set_resolution.c\
				srcs/ft_check_atoi_max_min.c\
				srcs/ft_str_isdigit.c\
				srcs/ft_handle_path.c\
				srcs/ft_handle_color.c\
				srcs/ft_handle_map.c\
				srcs/ft_check_n_parse_map.c\
				srcs/ft_print_error.c\
				srcs/ft_init_orientation.c\
				srcs/ft_prepare_textures_n_sprite.c\
				srcs/ft_free_data.c\
				srcs/ft_free_scene.c\
				srcs/ft_prepare_mlx.c\
				srcs/ft_raycasting.c\
				srcs/ft_handle_mouvement.c\
				srcs/ft_handle_image.c\
				srcs/ft_play_game.c\
				srcs/ft_handle_keyboard.c\
				srcs/ft_put_pixel_on_column.c\
				srcs/ft_put_pixel.c\
				srcs/ft_handle_sprite.c\

OBJS		=	${SRCS:.c=.o}

NAME		=	cub3D

GRAPH_FLAGS	=	-lmlx -framework OpenGL -framework AppKit -lm
CFLAGS		=	-o ${FLAGS}
FLAGS		=	-Wall -Wextra -Werror


CC			=	gcc
RM			=	rm -f
AR			=	ar rc

LIBFT		=	libft.a

.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o} -I./includes

${NAME}:		${LIBFT_OBJS} ${OBJS} ${INCLUDES}
				make -C libft
				${CC} -o ${NAME}\
				${FLAGS}\
				${GRAPH_FLAGS}\
				${OBJS}\
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

screenshot:
				./${NAME} scene_description/subject.cub -save

norm:
				make norm -C ${LIBFT_PATH}
				norminette -R CheckForbiddenSourceHeader srcs includes

leaks:
				leaks ${NAME}

commit:
				git add -A && git commit

.PHONY :		 all clean fclean re norm commit test
