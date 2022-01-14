#include "lib.h"

static void	ktb(long i, int fd)
{
	write (fd, &i, 1);
}

static int	putnbrr(long n, int fd)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
		i += 1;
	}
	if (n <= 9)
	{
		ktb (n + 48, fd);
		i += 1;
	}
	else
	{
		i += putnbrr(n / 10, fd);
		i += putnbrr(n % 10, fd);
	}
	return (i);
}

void	ft_printf_d(long n, int fd)
{
	int	i;

	i = putnbrr(n, fd);
	write (fd, "\n", 2);
}