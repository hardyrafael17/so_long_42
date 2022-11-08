# Files
NAME			=	so_long
LIBFT			=   libs/libft/libft.a
LIBMLX			=	libs/mlx_linux/mlxlib.a

# Sources and objects
GNL_FILES		=	$(wildcard get_next_line/*.c)
MAP				=	$(wildcard map/*.c)
UTILS			=	$(wildcard utils/*.c)
PROJECT_FILES	= 	$(wildcard *.c)
SRCS			=	$(GNL_FILES) $(PROJECT_FILES) $(MAP) $(UTILS)
OBJS			=	$(SRCS:.c=.o)
DEBUG_MAIN		=	.main.c

#Literals
GCC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
RM				=	rm -rf

#AR				=	ar rcs
LIBRARY_LINK_FT	=	-Llibs/libft -lft
LIBRARY_LINK_MLX=	-Llibs/mlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz
#LIBRARY_LINK_MAC=	-Llibs/mlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(GCC) $(CFLAGS) $(OBJS) $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) -o $(NAME)

.debug: .main.c $(LIBFT) $(PROJECT_FILES)
	$(GCC) $(DEBUG_MAIN) $(PROJECT_FILES) $(GNL_FILES) $(LIBRARY_LINK_MLX)
	$(LIBRARY_LINK_FT) -o .debug

$(LIBFT): $(LIBMLX)
	make -C libs/libft

$(LIBMLX): libs/mlx_linux/mlx.h
	make -C libs/mlx_linux

%.o%.c: $(SRCS) $(LIBFT)
	$(GCC) $(CFLAGS) -c $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libs/libft
	make clean	-C libs/mlx_linux

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libs/libft
	make clean	-C libs/mlx_linux
	$(RM) .debug

re: fclean all

run: all
	$(shell ./so_long)

.PHONY: all clean fclean re run
