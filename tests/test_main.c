/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 11:03:31 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/06 17:13:13 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"
#include <assert.h>
#include <ctype.h>
#include <stddef.h>
#include <stdio.h>
#include <string.h>

// #include <strings.h>

void	test_print_ok(char *ft_name)
{
	printf("%s : ok\n", ft_name);
}

void	test_assert_class(char *ft_name, int c, int custom, int origin)
{
	printf("%s: c = %d, %d vs %d\n", ft_name, c, custom, origin);
	assert((custom == 0 && origin == 0) || (custom != 0 && origin != 0));
}

void	test_assert_s2n(char *ft_name, char *param1, size_t custom,
		size_t origin)
{
	printf("%s: param1 = %s, %zu vs %zu\n", ft_name, param1, custom, origin);
	assert(custom == origin);
}

void	test_assert_sin2ip(char *ft_name, char *param1, int param2,
		size_t param3, unsigned char *custom, unsigned char *origin)
{
	size_t	i;

	printf("%s: param1 = %s, param2 = %d, param3 = %zu\n", ft_name, param1,
		param2, param3);
	i = 2 * param3;
	while (i)
	{
		printf("%d vs %d\n", *custom, *origin);
		assert(*custom == *origin);
		++custom;
		++origin;
		--i;
	}
}

void	test_ft_isalpha(void)
{
	char	*name;
	int		c;

	name = "ft_isalpha";
	c = -1;
	while (c <= 255)
	{
		test_assert_class(name, c, ft_isalpha(c), isalpha(c));
		++c;
	}
	test_print_ok(name);
}

void	test_ft_isdigit(void)
{
	char	*name;
	int		c;

	name = "ft_isdigit";
	c = -1;
	while (c <= 255)
	{
		test_assert_class("ft_isdigit", c, ft_isdigit(c), isdigit(c));
		++c;
	}
	test_print_ok(name);
}

void	test_ft_isalnum(void)
{
	char	*name;
	int		c;

	name = "ft_isalnum";
	c = -1;
	while (c <= 255)
	{
		test_assert_class("ft_isalnum", c, ft_isalnum(c), isalnum(c));
		++c;
	}
	test_print_ok(name);
}

void	test_ft_isascii(void)
{
	char	*name;
	int		c;

	name = "ft_isascii";
	c = -1;
	while (c <= 255)
	{
		test_assert_class("ft_isascii", c, ft_isascii(c), isascii(c));
		++c;
	}
	test_print_ok(name);
}

void	test_ft_isprint(void)
{
	char	*name;
	int		c;

	name = "ft_isprint";
	c = -1;
	while (c <= 255)
	{
		test_assert_class("ft_isprint", c, ft_isprint(c), isprint(c));
		++c;
	}
	test_print_ok(name);
}

void	test_ft_strlen(void)
{
	char	*name;
	char	*s;

	name = "ft_strlen";
	s = "test";
	test_assert_s2n(name, s, ft_strlen(s), strlen(s));
	s = "";
	test_assert_s2n(name, s, ft_strlen(s), strlen(s));
	test_print_ok(name);
}

void	test_ft_memset(void)
{
	char	*name;
	int		i;
	size_t	n;
	char	s[10] = "testtest";
	char	s1[10] = "testtest";
	char	s2[10] = "testtest";

	name = "ft_memset";
	n = 5;
	i = 33;
	test_assert_sin2ip(name, s, i, n, ft_memset(s1, i, n), memset(s2, i, n));
	test_print_ok(name);
}

void	test_ft_bzero(void)
{
	char	*name;
	char	s1[10] = "testtest";
	char	s2[10] = "testtest";
	size_t	n;
	size_t	i;

	name = "ft_bzero";
	n = 5;
	printf("%s: param1 = %s, param2 = %zu\n", name, "testtest", n);
	i = 0;
	ft_bzero(s1, n);
	bzero(s2, n);
	while (2 * n - i)
	{
		printf("%d vs %d\n", s1[i], s2[i]);
		assert(s1[i] == s2[i]);
		++i;
	}
	test_print_ok(name);
}

void	test_ft_memcpy(void)
{
	char	*name;
	char	src1[10] = "testtest";
	char	src2[10] = "testtest";
	char	dest1[10];
	char	dest2[10];
	size_t	n;
	int		size;

	name = "ft_memcpy";
	size = 10;
	n = 5;
	printf("%s: param2 = %s, param3 = %zu\n", name, src1, n);
	memset(dest1, 0, size);
	memset(dest2, 0, size);
	ft_memcpy(dest1, src1, n);
	memcpy(dest2, src2, n);
	while (size)
	{
		printf("%d vs %d\n", dest1[size - 1], dest2[size - 1]);
		--size;
	}
	test_print_ok(name);
}

int	main(void)
{
	test_ft_isalpha();
	test_ft_isdigit();
	test_ft_isalnum();
	test_ft_isascii();
	test_ft_isprint();
	test_ft_strlen();
	test_ft_memset();
	test_ft_bzero();
	test_ft_memcpy();
}
