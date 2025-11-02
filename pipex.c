
#include "pipex.h"


int	main(int argc, char const *argv[])
{
	int	fd1;
	int	fd2;

	if (argc != 5)
	{
		write(2, "Error: 4 arguments required.\n", 30);
		exit(1);
	}

	return 0;
}
