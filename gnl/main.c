#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char *get_next_line(int fd);

int	main(int ac, char **av)
{
	if (ac != 2) {
		puts("no args!");
		return (1);
	}
	char	*line;
	int		fd;

	line = NULL;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		printf("open returns -1\n%s\n", strerror(errno));
		return (-1);
	}
	while (line = get_next_line(fd))
	{
		puts(line);
		free(line);
	}
	printf("errno: %s\n", strerror(errno));
	close(fd);
	return (0);
	(void)ac;
	(void)av;
}
