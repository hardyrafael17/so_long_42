# Files
NAME			=	so_long
LIBFT			=   libft/libft.a
LIBMLX			=	mlx/mlxlib.a

# Sources and objects
GNL_FILES		=	get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
SRCS			=	so_long.c validate_map.c $(GNL_FILES)
OBJS			=	$(SRCS:.c=.o)

#Literals
GCC				=	gcc
FLAGS			=	-Wall -Wextra -Werror
RM				=	rm -rf
AR				=	ar rcs
LIBRARY_LINK_FT	=	-Llibft -lft
LIBRARY_LINK_MLX=	-Lmlx -lmlx -framework OpenGL -framework AppKit

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(GCC) $(FLAGS) $(OBJS) $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) -o $(NAME)

.debug: .main.c $(LIBFT) $(GNL_FILES) validate_map.c
	gcc -g .main.c validate_map.c $(GNL_FILES) $(LIBRARY_LINK_FT) -o .debug

$(LIBFT): $(LIBMLX)
	make -C libft

$(LIBMLX): mlx/mlx.h
	make -C mlx

%.o%.c: $(SRCS) $(LIBFT)
	$(GCC) $(FLAGS) -c $(LIBRARY_LINK_FT) $< -o $@

clean:
	rm -rf $(OBJS)
	make clean -C libft
	make clean	-C mlx

fclean:	clean
	rm -rf $(NAME)
	make fclean -C libft
	make clean -C mlx
	rm -rf .debug

re: fclean all

run: all
	$(shell ./so_long)

.PHONY: all clean fclean re run 
