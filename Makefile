NAME := fractol
MLX_DIR := ./minilibx-linux
MLX := ${MLX_DIR}/libmlx.a
LIBFT_DIR = ./libft
LIBFT := ${LIBFT_DIR}/libft.a
LIBRARIES  := -lft -lmlx -lX11 -lXext -lm
LIBRARIES_DIR := -L${LIBFT_DIR} -L${MLX_DIR}
HEADERS_DIR := ./headers
HEADERS := -I${HEADERS_DIR} -I${MLX_DIR} -I${LIBFT_DIR}
CFLAGS := -Wall -Werror -Wextra -Ofast
OBJS_DIR = obj
SRCS_DIR = src
CC = gcc
RM := rm -rf

FUNCTIONS := main.c 			\
			 check_input.c 		\
			 errors_handler.c	\
			 init_mlx.c			\
			 calc_fractol.c		\
			 gen_img.c			\
			 hooks.c

SRCS := ${addprefix ${SRCS_DIR}/,${FUNCTIONS}}
OBJS := ${addprefix ${OBJS_DIR}/,${SRCS:${SRCS_DIR}/%.c=%.o}}

all: 	 ${NAME}

${NAME}:${MLX} ${LIBFT} ${OBJS}
		${CC} ${CFLAGS} ${OBJS} ${HEADERS} -o ${NAME} ${LIBRARIES_DIR} ${LIBRARIES}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c ${HEADERS_DIR}/fractol.h
		@mkdir -p ${OBJS_DIR}
		${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

${MLX}:
		@git submodule update --init
		${MAKE} -C ${MLX_DIR}

${LIBFT}:
		${MAKE} bonus -C ${LIBFT_DIR}


clean:
		${RM} ${OBJS_DIR}
		${RM} ${MLX_DIR}/obj
		${MAKE} clean -C ${LIBFT_DIR}

fclean:	clean
		${RM} ${NAME}
		${MAKE} clean -C ${MLX_DIR}
		${MAKE} fclean -C ${LIBFT_DIR}

re:	fclean all

bonus: all

.PHONY: all clean fclean re
