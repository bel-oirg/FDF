SRC = get_next_line.c get_next_line_utils.c strtok_two.c \
	  ft_convert.c fdf_utils.c my_malloc.c strtok.c main.c \
	  fdf_utils_2.c ft_split.c

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
