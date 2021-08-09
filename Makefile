NAME := fractol
MLX_DIR := ./minilibx-linux
MLX := ${MLX_DIR}/libmlx.a
LIBRARIES  := -lmlx -lX11 -lXext
HEADERS := -I. -I${MLX_DIR}
CFLAGS := -Wall -Werror -Wextra
OBJS_DIR = obj
SRCS_DIR = src
CC = clang
RM := rm -rf
FUNCTIONS := main.c
SRCS := ${addprefix ${SRCS_DIR}/,${FUNCTIONS}}
OBJS := ${addprefix ${OBJS_DIR}/,${SRCS:${SRCS_DIR}/%.c=%.o}}

${NAME}: ${OBJS} ${MLX}
		${CC} ${CFLAGS} ${OBJS} ${HEADERS} -o ${NAME} -L${MLX_DIR} ${LIBRARIES}

${OBJS_DIR}/%.o: ${SRCS_DIR}/%.c
		@mkdir -p ${OBJS_DIR}
		${CC} ${CFLAGS} -I. -I${MLX_DIR} -c $< -o $@

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
