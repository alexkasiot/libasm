#include <stdio.h>

size_t ft_strlen(const char* s)
{
	size_t i;

	i = 0;
	while (s[i] != 0)
	{
		i++;
	}
	return (i);
}

int main(int argc, const char* argv[])
{

	if (argc != 2)
	{
		printf("Usage: ./strlen [string]\n");
		return 1;
	}
	printf("%zu\n", ft_strlen(argv[1]));
	return 0;
}