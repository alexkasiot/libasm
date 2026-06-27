#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

void test_ft_strlen()
{
	printf("test \"\":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen(""), ft_strlen(""));
	printf("test \"a\":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("a"), ft_strlen("a"));
	printf("test \"hello\":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("hello"), ft_strlen("hello"));
	printf("test \"hello world\":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("hello world"), ft_strlen("hello world"));
	printf("test \" \":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen(" "), ft_strlen(" "));
	printf("test \"\\n\":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("\n"), ft_strlen("\n"));
	printf("test \"abc\\0def\" (embedded NUL):\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("abc\0def"), ft_strlen("abc\0def"));
	printf("test \" \\t \" (space,tab,space):\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen(" \t "), ft_strlen(" \t "));
	printf("test binary \"\\xFF\\xFE\":\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("\xFF\xFE"), ft_strlen("\xFF\xFE"));
	printf("test UTF-8 \"é\" (U+00E9):\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen("\xC3\xA9"), ft_strlen("\xC3\xA9"));
	/* Stress test: allocate 1_000_000 'a's and compare */
	{
		size_t n = 1000000;
		char *big = malloc(n + 1);
		if (big) {
			memset(big, 'a', n);
			big[n] = '\0';
			printf("test 1_000_000 'a's:\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen(big), ft_strlen(big));
			free(big);
		} else {
			printf("skip big test: malloc failed\n");
		}
	}
}

int main(int argc, const char* argv[])
{
	if (argc != 2)
	{
		write(1, "Usage ./test [function_name]\n", 29);
		return 1;
	}

	if (strcmp(argv[1], "ft_strlen") == 0)
		test_ft_strlen();
	else
	{
		write(1, "Usage ./test [function_name]\n", 29);
		return 1;
	}
	return 0;
}