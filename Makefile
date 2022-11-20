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
	LIBRARY_LINK_MLX=	-Lmlx -lmlx -framework OpenGL -framework AppKit
endif
# Files
LIBFT			=   libs/libft/libft.a

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
LIBRARY_LINK_FT	=	-Llibs/libft -lft

test:
	echo $(O_SYSTEM)

# Rules
all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(GCC) $(CFLAGS) $(OBJS) $(LIBRARY_LINK_MLX) $(LIBRARY_LINK_FT) -o $(NAME)

.debug: .main.c $(LIBFT) $(PROJECT_FILES)
	$(GCC) $(DEBUG_MAIN) $(PROJECT_FILES) $(GNL_FILES) $(LIBRARY_LINK_MLX)
	$(LIBRARY_LINK_FT) -o .debug

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
	$(RM) .debug

re: fclean all

run: all
	$(shell ./so_long)

.PHONY: all clean fclean re run
