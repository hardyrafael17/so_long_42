#include "../so_long.h"

static void	ft_print_usage(void)
{
	printf("To start the game please type 'so_long map.ber'\n\n");
	printf("To move, use the keys 'a', 's', 'd', 'w', left, down, right and up");
	printf(" respectively, \n use the 'Esc' to exit the game without confirm");
	printf("ation.\n\n The objective is to collect all the gifts, then exit the game");
	printf(" with the girl\n\n");
	printf("Enjoy!!!!\n\n");
	exit(0);
}

void	ft_check_args(int argc, char *argv[])
{
	if (argc > 2)
	{
		printf("Too many argumements, only one argument allowed, a valid map!\n");
		exit(1);
	}
	else if (argc < 2) {
		printf("Please provide a valid map as argument\n");
		exit(1);
	}
	if (!ft_strncmp(argv[1], "-h", 3) || !(ft_strncmp(argv[1], "--help", 7)))
	{
		ft_print_usage();
		exit(0);
	}
	else if (ft_strncmp(argv[1], "map.ber", 8))
	{
		printf("Map name must be 'map.ber'!\n");
		exit(1);
	}
}
