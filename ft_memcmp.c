/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 16:55:04 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/07 17:00:29 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*u_s1 = (const unsigned char *)s1;
	const unsigned char	*u_s2 = (const unsigned char *)s2;

	if (!n--)
		return (0);
	while (*u_s1 == *u_s2 && n--)
	{
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}
