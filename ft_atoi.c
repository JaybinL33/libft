/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/29 15:46:19 by jungblee          #+#    #+#             */
/*   Updated: 2026/04/29 15:46:19 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stddef.h>

static int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned)c - '\t' <= '\r' - '\t');
}

int	ft_atoi(const char *nptr)
{
	int	n;
	int	neg_flag;
	int	mask;

	n = 0;
	neg_flag = 0;
	while (ft_isspace(*nptr))
		nptr++;
	if (((*nptr + 1) | 2) == '-' + 1)
		neg_flag = ((*nptr++ + 1) & 2) >> 1;
	while (ft_isdigit(*nptr))
		n = 10 * n - (*nptr++ - '0');
	mask = neg_flag - 1;
	return ((mask ^ n) - mask);
}
