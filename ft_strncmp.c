/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/27 19:27:27 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/28 08:49:06 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	const unsigned char	*u_s1 = (unsigned char *)s1;
	const unsigned char	*u_s2 = (unsigned char *)s2;

	if (!n)
		return (0);
	while (*u_s1 && *u_s1 == *u_s2 && --n)
	{
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}
