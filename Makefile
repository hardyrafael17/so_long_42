
# Files

NAME			=	so_long
LIB_MXL			=	mlx/libmlx.a
LIB_FT			= 	libft/libft.a
GNL_FILES		=	get_next_line/%.c

# Sources and objects

SRC				=	singleton.c
OBJS			=	$(SRC:.c=.o)

# Literals
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-Imlx # Includes mlx folder #
PROGRAM			=	singleton
RM				=	rm -rf
AR				=	ar rcs
LIBMLX			=	cd mlx && make
LIBFT			=	cd libft && make
CLEAN_LIB		=   cd mlx && make clean
LIBRARY_LINK	=	-Lmlx -lmlx -framework OpenGL -framework AppKit #Links apple kit

# Rules

all: $(NAME)

$(NAME): $(OBJ) $(LIB)
	$(GCC) $(FLAGS) $(OBJ) $(LIBRARY_LINK) -o $@

$(LIB):
	$(LIBMLX)

%.o%.c:
	$(GCC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJ);
fclean:	clean
	rm -rf $(NAME)
	$(CLEAN_LIB)

re: fclean all

run: all
	$(shell ./singleton)

.PHONY: all clean fclean re run


