#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <errno.h>
#include <string.h>

char *get_next_line(int fd);

int	main(int ac, char **av)
{
	if (ac != 3) {
		puts("bad args!");
		return (1);
	}
	char 	*line1;
	char 	*line2;
	int 	fd1;
	int 	fd2;

	line1 = NULL;
	line2 = NULL;
	fd1 = open(av[1], O_RDONLY);
	fd2 = open(av[2], O_RDONLY);
	if (fd1 == -1 || fd2 == -1)
	{
		printf("open returns -1\n%s\n", strerror(errno));
		return (-1);
	}
	while (line1 = get_next_line(fd1))
	{
		puts(line1);
		free(line1);
		break ;
	}
	printf("errno: %s\n", strerror(errno));
	while (line2 = get_next_line(fd2))
	{
		puts(line2);
		free(line2);
	}
	printf("errno: %s\n", strerror(errno));
	while (line1 = get_next_line(fd1))
	{
		puts(line1);
		free(line1);
	}
	printf("errno: %s\n", strerror(errno));
	close(fd1);
	close(fd2);
	return (0);
	(void)ac;
	(void)av;
}

//check ctrl D EOF
