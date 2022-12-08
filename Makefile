NAME			=	so_long
#detect OS
O_SYSTEM := $(shell uname)
ifeq ($(O_SYSTEM), Linux)
	LIBMLX			=	libs/mlx_linux/mlxlib.a
	OS_LIB_DIR		=	libs/mlx_linux
	LIBRARY_LINK_MLX=	-Llibs/mlx_linux -lmlx -Imlx_linux -lXext -lX11 -lm -lz
else
	LIBMLX			=	libs/mlx/mlxlib.a
	OS_LIB_DIR		=	libs/mlx
	LIBRARY_LINK_MLX=	-Llibs/mlx -lmlx -framework OpenGL -framework AppKit
endif
# Files
LIBFT			=   libs/libft/libft.a

# Sources and objects
GNL_FILES		=	$(wildcard get_next_line/*.c)
MAP				=	$(wildcard map/*.c)
UTILS			=	$(wildcard utils/*.c)
ERRORS			=	$(wildcard errors/*.c)
PROJECT_FILES	= 	$(wildcard *.c)
EVENTS			=	$(wildcard events/*.c)
IMAGE			=	$(wildcard images/*.c)
SRCS			=	$(GNL_FILES) $(PROJECT_FILES) $(MAP) $(UTILS) $(EVENTS) \
					$(IMAGE) $(ERRORS)
OBJS			=	$(SRCS:.c=.o)

#Literals
GCC				=	gcc
CFLAGS			=	-g -Wall -Wextra -Werror
RM				=	rm -rf

#AR				=	ar rcs
LIBRARY_LINK_FT	=	-Llibs/libft -lft

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT) $(LIBMLX)
	$(GCC) $(CFLAGS) $(OBJS) $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) -o $(NAME)

$(LIBFT):
	make -C libs/libft

$(LIBMLX):
	make -C $(OS_LIB_DIR)

%.o%.c: $(SRCS) $(LIBFT) 
	$(GCC) $(CFLAGS) -c $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) $< -o $@

clean:
	$(RM) $(OBJS)
	make clean -C libs/libft
	make clean	-C $(OS_LIB_DIR) 

fclean:	clean
	$(RM) $(NAME)
	make fclean -C libs/libft
	make clean	-C $(OS_LIB_DIR) 

re: fclean all

run: all
	$(shell ./so_long map.ber)

.PHONY: all clean fclean re run
