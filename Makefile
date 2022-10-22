# Files
NAME			=	so_long
LIBFT			=   libft/libft.a
LIBMLX			=	mlx_linux/mlxlib.a

# Sources and objects
GNL_FILES		=	get_next_line/get_next_line.c \
					get_next_line/get_next_line_utils.c
PROJECT_FILES	=	validate_map.c		\
					events.c			\
					utils.c				\
					fill_map.c			\
					controller.c
SO_LONG			=	so_long.c
SRCS			=	$(GNL_FILES) $(PROJECT_FILES) $(SO_LONG)
OBJS			=	$(SRCS:.c=.o)
DEBUG_MAIN		=	.main.c
#Literals
GCC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
RM				=	rm -rf
#AR				=	ar rcs
LIBRARY_LINK_FT	=	-Llibft -lft
LIBRARY_LINK_MLX=	-Lmlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(GCC) $(CFLAGS) $(OBJS) $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) -o $(NAME)

.debug: .main.c $(LIBFT) $(PROJECT_FILES)
	$(GCC) $(DEBUG_MAIN) $(PROJECT_FILES) $(GNL_FILES) $(LIBRARY_LINK_MLX) \
	$(LIBRARY_LINK_FT) -o .debug

$(LIBFT): $(LIBMLX)
	make -C libft

$(LIBMLX): mlx_linux/mlx.h
	make -C mlx_linux

%.o%.c: $(SRCS) $(LIBFT)
	$(GCC) $(CFLAGS) -c $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libft
	make clean	-C mlx_linux

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libft
	make clean	-C mlx_linux
	$(RM) .debug

re: fclean all

run: all
	$(shell ./so_long)

.PHONY: all clean fclean re run
