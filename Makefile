SRC = get_next_line.c get_next_line_utils.c ft_convert.c \
		my_malloc.c  fdf_utils_2.c \
		ft_split.c parser_fdf.c algo_utils.c  cleaning.c \
		gradient.c math_utils.c three_dim.c algo.c init_v.c
		
SRC_B = keyboard.c mouse.c

OBJ = ${SRC:.c=.o}
OBJ_B = ${SRC_B:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror #-fsanitize=address 
GFLAGS = -lmlx -Lminilibx_macos -framework OpenGL -framework APPKit
NAME = fdf

all: ${OBJ}
	${CC} ${FLAGS} ${GFLAGS} ${OBJ} main.c -o fdf

%o : %c fdf.h
	${CC} ${FLAGS} -c $< -o $@

bonus: ${OBJ} ${OBJ_B}
	${CC} ${FLAGS} ${GFLAGS} ${OBJ} ${OBJ_B} main_bonus.c -o fdf_bonus

clean:
	rm -f ${OBJ} ${OBJ_B}

fclean:
	rm -f ${OBJ} ${OBJ_B} fdf fdf_bonus

re: clean all

.PHONY: clean fclean re all