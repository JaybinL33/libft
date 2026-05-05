/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/06 11:54:49 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/06 11:54:49 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>
#include <stdlib.h>

static void	*ft_del_argv(char **argv, size_t argi)
{
	while (argi)
		free(argv[--argi]);
	free(argv);
	return (NULL);
}

static size_t	ft_arg_count(char const *s, char c)
{
	size_t	argc;

	argc = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			argc++;
		while (*s && *s != c)
			s++;
	}
	return (argc);
}

static size_t	ft_word_len(char const *s, char c)
{
	char const	*s_curr;

	s_curr = s;
	while (*s_curr && *s_curr != c)
		s_curr++;
	return (s_curr - s);
}

static char	*ft_fill_word(char **argv, size_t argi, char const *s, size_t len)
{
	argv[argi] = malloc(sizeof(char) * (len + 1));
	if (!argv[argi])
		return (NULL);
	ft_memcpy(argv[argi], s, len);
	argv[argi][len] = '\0';
	return (argv[argi]);
}

char	**ft_split(char const *s, char c)
{
	char	**argv;
	size_t	argc;
	size_t	argi;
	size_t	len;

	argc = ft_arg_count(s, c);
	argv = malloc(sizeof(char *) * (argc + 1));
	if (!argv)
		return (NULL);
	argi = 0;
	while (argi < argc)
	{
		while (*s == c)
			s++;
		len = ft_word_len(s, c);
		if (!ft_fill_word(argv, argi, s, len))
			return (ft_del_argv(argv, argi));
		s += len;
		argi++;
	}
	argv[argc] = NULL;
	return (argv);
}
