NAME := fractol
MLX := mlx
MLX_DIR := ./minilibx-linux
CFLAGS := -Wall -Werror -Wextra
OBJS_DIR = ./obj
SRCS_DIR = ./src
CC = clang
RM := rm -rf
SRCS := ${addprefix ${SRCS_DIR}/,${FUNCTIONS}}
OBJS := ${addprefix ${OBJS_DIR}/,${SRCS:${SRCS_DIR}/%.c=%.o}}

${NAME}: ${OBJS} ${MLX}
		${CC} ${CFLAGS} ${OBJS} -I${MLX_DIR} -o ${NAME} -L${MLX_DIR} -l${MLX}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
		@mkdir -p ${OBJS_DIR}
		${CC} ${CFLAGS} -c $< -o $@

${MLX}:
		${MAKE} -C ${MLX_DIR}

all: 	${NAME}

clean:
		${RM} ${OBJS_DIR}
		${RM} ${MLX_DIR}/obj

fclean:	clean
		${RM} ${NAME}
		${MAKE} clean -C ${MLX_DIR}

re:	fclean all
.PHONY: all clean fclean re
