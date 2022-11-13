# Files
NAME			=	so_long
LIBFT			=   libs/libft/libft.a
LIBMLX			=	libs/mlx/mlxlib.a

# Sources and objects
GNL_FILES		=	$(wildcard get_next_line/*.c)
MAP				=	$(wildcard map/*.c)
UTILS			=	$(wildcard utils/*.c)
PROJECT_FILES	= 	$(wildcard *.c)
EVENTS			=	$(wildcard events/*.c)
IMAGE			=	$(wildcard images/*.c)
SRCS			=	$(GNL_FILES) $(PROJECT_FILES) $(MAP) $(UTILS) $(EVENTS) \
					$(IMAGE)
OBJS			=	$(SRCS:.c=.o)

#Literals
GCC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
RM				=	rm -rf

#AR				=	ar rcs
LIBRARY_LINK_FT	=	-Llibft -lft
LIBRARY_LINK_MLX=	-Lmlx -lmlx -framework OpenGL -framework AppKit

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(GCC) $(CFLAGS) $(OBJS) $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) -o $(NAME)

.debug: .main.c $(LIBFT) $(PROJECT_FILES)
	$(GCC) $(DEBUG_MAIN) $(PROJECT_FILES) $(GNL_FILES) $(LIBRARY_LINK_MLX)
	$(LIBRARY_LINK_FT) -o .debug

$(LIBFT): $(LIBMLX)
	make -C libs/libft

$(LIBMLX): libs/mlx/mlx.h
	make -C libs/mlx

%.o%.c: $(SRCS) $(LIBFT)
	$(GCC) $(CFLAGS) -c $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libs/libft
	make clean	-C libs/mlx

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libs/libft
	make clean	-C libs/mlx
	$(RM) .debug

re: fclean all

run: all
	$(shell ./so_long map.ber)

.PHONY: all clean fclean re run
