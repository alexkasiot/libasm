#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include "libasm.h"

static void test_ft_strlen()
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
		if (big)
		{
			memset(big, 'a', n);
			big[n] = '\0';
			printf("test 1_000_000 'a's:\nstrlen:    %zu\nft_strlen: %zu\n\n", strlen(big), ft_strlen(big));
			free(big);
		}
		else
		{
			printf("skip big test: malloc failed\n");
		}
	}
}

static void test_ft_strcpy()
{
	char dest[50];

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "hello", strcpy(dest, "hello"), ft_strlen(strcpy(dest, "hello")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, "hello"), ft_strlen(strcpy(dest, "hello")));

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "", strcpy(dest, ""), ft_strlen(strcpy(dest, "")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, ""), ft_strlen(strcpy(dest, "")));

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "a", strcpy(dest, "a"), ft_strlen(strcpy(dest, "a")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, "a"), ft_strlen(strcpy(dest, "a")));

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "hello world", strcpy(dest, "hello world"), ft_strlen(strcpy(dest, "hello world")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, "hello world"), ft_strlen(strcpy(dest, "hello world")));

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "!@#$%%^", strcpy(dest, "!@#$%%^"), ft_strlen(strcpy(dest, "!@#$%%^")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, "!@#$%%^"), ft_strlen(strcpy(dest, "!@#$%%^")));

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "hello\nworld", strcpy(dest, "hello\nworld"), ft_strlen(strcpy(dest, "hello\nworld")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, "hello\nworld"), ft_strlen(strcpy(dest, "hello\nworld")));

	printf("src: %s\nstrcpy_dest:    %s|len: %zu\n", "The quick brown fox jumps over the lazy dog", strcpy(dest, "The quick brown fox jumps over the lazy dog"), ft_strlen(strcpy(dest, "The quick brown fox jumps over the lazy dog")));
	printf("ft_strcpy_dest: %s|len: %zu\n", ft_strcpy(dest, "The quick brown fox jumps over the lazy dog"), ft_strlen(strcpy(dest, "The quick brown fox jumps over the lazy dog")));
}

static void test_ft_strcmp()
{
	// printf("%i", strcmp("hello", "hcllo"));
	char s1[] = "hello";
	char s2[] = "hcllo";
	printf("s1: %s\ns2: %s\nstrcmp:    %i\nft_strcmp: %i\n\n", s1, s2, strcmp(s1, s2), ft_strcmp(s1, s2));

	char s3[] = "hello";
	char s4[] = "hello";
	printf("s3: %s\ns4: %s\nstrcmp:    %i\nft_strcmp: %i\n\n", s3, s4, strcmp(s3, s4), ft_strcmp(s3, s4));

	char s5[] = "hello";
	char s6[] = "hel";
	printf("s5: %s\ns6: %s\nstrcmp:    %i\nft_strcmp: %i\n\n", s5, s6, strcmp(s5, s6), ft_strcmp(s5, s6));

	char s7[] = "hel";
	char s8[] = "hello";
	printf("s7: %s\ns8: %s\nstrcmp:    %i\nft_strcmp: %i\n\n", s7, s8, strcmp(s7, s8), ft_strcmp(s7, s8));

	char s9[] = "";
	char s10[] = "";
	printf("s9: %s\ns10: %s\nstrcmp:    %i\nft_strcmp: %i\n\n", s9, s10, strcmp(s9, s10), ft_strcmp(s9, s10));

	char s11[] = "";
	char s12[] = "hello";
	printf("s11: %s\ns12: %s\nstrcmp:    %i\nft_strcmp: %i\n\n", s11, s12, strcmp(s11, s12), ft_strcmp(s11, s12));

	char s13[] = "abc";
	char s14[] = "xyz";
	printf("s13: %s\ns14: %s\nstrcmp:    %i\nft_strcmp: %i\n", s13, s14, strcmp(s13, s14), ft_strcmp(s13, s14));
}

static void test_ft_write_block(int fd, const void *buf, size_t count)
{
	ssize_t write_ret;
	ssize_t ft_write_ret;
	write(fd, "---------------------------\n", 28);
	write(fd, "write:    ", 10);
	write_ret = write(fd, buf, count);
	dprintf(fd, "write_ret:    %zd\n", write_ret);
	write(fd, "ft_write: ", 10);
	ft_write_ret = ft_write(fd, buf, count);
	dprintf(fd, "ft_write_ret: %zd\n", ft_write_ret);
	write(fd, "---------------------------\n", 28);
}

void test_ft_write()
{
	char s1[] = "hello\n";
	write(1, "STDOUT 'hello\\n'\n", 17);
	test_ft_write_block(1, s1, ft_strlen(s1));
	write(2, "STDERR 'hello\\n'\n", 17);
	test_ft_write_block(2, s1, ft_strlen(s1));
	write(1, "Terminator in between\n", 22);
	char binary[] = {'a', 'b', '\0', 'c', '\n'};
	test_ft_write_block(1, binary, sizeof(binary));
	write(1, "A bit longer string\n", 20);
	char longmsg[] = "The quick brown fox jumps over the lazy dog\n";
	test_ft_write_block(1, longmsg, ft_strlen(longmsg));
	write(1, "Empty\n", 6);
	test_ft_write_block(1, "", 0);

	write(1, "Error\n", 6);
	write(1, "---------------------------\n", 28);
	ssize_t write_ret = write(10, "", 1);
	printf("write_ret:    %zd\nerrno: %d (%s)\n", write_ret, errno, strerror(errno));
	ssize_t ft_write_ret = ft_write(10, "", 1);
	printf("ft_write_ret: %zd\nerrno: %d (%s)\n", ft_write_ret, errno, strerror(errno));
}

static void test_ft_read()
{
	size_t read_ret;
	size_t ft_read_ret;
	char test[100] = {0};
	ft_write(1, "read:    ", 9);
	read_ret = read(0, test, 100);
	ft_write(1, test, ft_strlen(test));
	dprintf(1, "read_ret:    %zu\n", read_ret);

	memset(test, 0, 100);

	ft_write(1, "ft_read: ", 9);
	ft_read_ret = ft_read(0, test, 100);
	ft_write(1, test, ft_strlen(test));
	dprintf(1, "ft_read_ret: %zu\n", ft_read_ret);
}

int main(int argc, const char *argv[])
{
	if (argc != 2)
	{
		write(1, "Usage ./test [function_name]\n", 29);
		return 1;
	}

	if (strcmp(argv[1], "ft_strlen") == 0)
		test_ft_strlen();
	else if (strcmp(argv[1], "ft_strcpy") == 0)
		test_ft_strcpy();
	else if (strcmp(argv[1], "ft_strcmp") == 0)
		test_ft_strcmp();
	else if (strcmp(argv[1], "ft_write") == 0)
		test_ft_write();
	else if (strcmp(argv[1], "ft_read") == 0)
		test_ft_read();
	else
	{
		write(1, "Usage ./test [function_name]\n", 29);
		return 1;
	}
	return 0;
}