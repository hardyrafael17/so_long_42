
# Files

NAME			=	so_long
LIBMXL			=	mlx/libmlx.a
LIBFT			= 	libft/libft.a

# Sources and objects

GNL_FILES		=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRCS			=	so_long.c $(GNL_FILES)
OBJS			=	$(SRCS:.c=.o)

# Literals
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
INCLUDE			=	-Imlx Ilibft # Includes mlx folder #
RM				=	rm -rf
AR				=	ar rcs
LIB_MLX			=	cd mlx && make
LIB_FT			=	cd libft && make
LIBRARY_LINK	=	-Lmlx -lmlx -framework OpenGL -framework AppKit #Links apple kit

# Rules

all: $(NAME)

$(NAME): $(OBJS) libs
	$(GCC) $(FLAGS) $(OBJS) $(LIBFT) $(LIBRARY_LINK) -o $@

libs:
	$(LIB_MLX)
	$(LIB_FT)

%.o%.c:
	$(GCC) $(FLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -rf $(OBJS);

fclean:	clean
	rm -rf $(NAME)
	cd mlx && make clean 
	cd libft && make clean

re: fclean all

run: all
	$(shell ./so_long)

.PHONY: libs all clean fclean re run cd libft mlx && make


