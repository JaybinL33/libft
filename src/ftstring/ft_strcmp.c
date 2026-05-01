/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/13 11:26:56 by jungblee          #+#    #+#             */
/*   Updated: 2026/07/13 14:32:05 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ftstring.h"
#include <stddef.h>

int	ft_strcmp(const char *s1, const char *s2)
{
	const unsigned char	*u_s1 = (unsigned char *)s1;
	const unsigned char	*u_s2 = (unsigned char *)s2;

	while (*u_s1 && *u_s1 == *u_s2)
	{
		u_s1++;
		u_s2++;
	}
	return (*u_s1 - *u_s2);
}
