SRC = get_next_line.c get_next_line_utils.c \
	  ft_convert.c  my_malloc.c strtok.c main.c keyboard.c\
	  fdf_utils_2.c ft_split.c parser_fdf.c \
	  algo_utils.c mouse.c gradient.c math_utils.c three_dim.c\
	  algo.c

OBJ = ${SRC:.c=.o}

CC = cc

FLAGS = -Wall -Wextra -Werror -g -fsanitize=address 
GFLAGS = -lmlx -Lminilibx_macos -framework OpenGL -framework APPKit
NAME = fdf

all: ${NAME}

%o : %c fdf.h
	${CC} ${FLAGS} -c $< -o $@

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${GFLAGS} ${OBJ} -o $@

clean:
	rm -f ${OBJ}

fclean:
	rm -f ${OBJ} ${NAME}

re: clean all

.PHONY: clean fclean re all
