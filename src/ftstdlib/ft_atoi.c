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

#include "ftctype.h"
#include "ftstdlib.h"

static int	ft_isspace(int c)
{
	return (c == ' ' || (unsigned)c - '\t' <= '\r' - '\t');
}

/*
 * Accumulates as a negative value to prevent INT_MIN overflow.
 * Uses (n ^ mask) - mask for branchless 2's complement negation.
 */
int	ft_atoi(const char *nptr)
{
	int	n;
	int	mask;

	while (ft_isspace(*nptr))
		nptr++;
	mask = -1;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			mask = 0;
		nptr++;
	}
	n = 0;
	while (ft_isdigit(*nptr))
		n = (10 * n) - (*nptr++ - '0');
	return ((n ^ mask) - mask);
}
