#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char *get_next_line(int fd);

int	main(int ac, char **av)
{
	if (ac != 1) {
		puts("should have no args!");
		return (1);
	}
	char	*line;
	int		ret;

	line = NULL;
	while (line = get_next_line(0))
	{
		puts(line);
		free(line);
	}
	printf("errno: %s\n", strerror(errno));
	return (0);
	(void)ac;
	(void)av;
}
