NAME := fractol
MLX_DIR := ./minilibx-linux
MLX := ${MLX_DIR}/libmlx.a
LIBFT_DIR = ./libft
LIBFT := ${LIBFT_DIR}/libft.a
LIBRARIES  := -lft -lmlx -lX11 -lXext
LIBRARIES_DIR := -L${LIBFT_DIR} -L${MLX_DIR}
HEADERS_DIR := ./headers
HEADERS := -I${HEADERS_DIR} -I${MLX_DIR} -I${LIBFT_DIR}
CFLAGS := -g -Wall -Werror -Wextra -O3
OBJS_DIR = obj
SRCS_DIR = src
CC = gcc
RM := rm -rf

FUNCTIONS := main.c \
			 check_input.c \
			 errors_handler.c	\
			 init_mlx.c			\
			 calc_fractol.c		\
			 gen_img.c

SRCS := ${addprefix ${SRCS_DIR}/,${FUNCTIONS}}
OBJS := ${addprefix ${OBJS_DIR}/,${SRCS:${SRCS_DIR}/%.c=%.o}}

${NAME}: ${OBJS} ${MLX} ${LIBFT}
		${CC} ${CFLAGS} ${OBJS} ${HEADERS} -o ${NAME} ${LIBRARIES_DIR} ${LIBRARIES}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
		@mkdir -p ${OBJS_DIR}
		${CC} ${CFLAGS} ${HEADERS} -c $< -o $@

${MLX}:
		${MAKE} -C ${MLX_DIR}

${LIBFT}:
		${MAKE} bonus -C ${LIBFT_DIR}

all: 	${NAME}

clean:
		${RM} ${OBJS_DIR}
		${RM} ${MLX_DIR}/obj
		${MAKE} clean -C ${LIBFT_DIR}

fclean:	clean
		${RM} ${NAME}
		${MAKE} clean -C ${MLX_DIR}
		${MAKE} fclean -C ${LIBFT_DIR}

re:	fclean all
.PHONY: all clean fclean re
