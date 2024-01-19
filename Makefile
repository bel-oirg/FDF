SRC = get_next_line.c get_next_line_utils.c ft_convert.c \
		my_malloc.c  fdf_utils_2.c algo.c init_v.c\
		ft_split.c parser_fdf.c algo_utils.c  cleaning.c \
		gradient.c math_utils.c three_dim.c 
SRC_B = keyboard.c mouse.c 

CC = cc

CFLAGS = -Wall -Wextra -Werror
GFLAGS = -lmlx -framework OpenGL -framework APPKit

NAME = fdf
NAME_B = fdf_bonus

all: ${NAME}

${NAME} : ${SRC} main.c fdf.h
	${CC} ${CFLAGS} ${GFLAGS} ${SRC} main.c -o fdf

bonus: ${NAME_B}

${NAME_B} : ${SRC} ${SRC_B} main_bonus.c fdf_bonus.h
	${CC} ${CFLAGS} ${GFLAGS} ${SRC} ${SRC_B} main_bonus.c -o fdf_bonus

clean:
	@echo "nothing to clean"

fclean:
	rm -f fdf fdf_bonus

re: fclean all

.PHONY: clean fclean re all