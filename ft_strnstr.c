/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/28 12:10:10 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/28 12:10:10 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const char	*l;
	const char	*b;
	size_t		l_len;
	char		l_c;

	if (!*little)
		return ((char *)big);
	l_len = ft_strlen(little);
	l_c = *little;
	while (*big && len-- >= l_len)
	{
		if (*big != l_c)
		{
			big++;
			continue ;
		}
		l = little;
		b = big;
		while (*++b == *++l && *l)
			;
		if (!*l)
			return ((char *)big);
		big++;
	}
	return (NULL);
}
