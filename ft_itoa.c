/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 10:52:19 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/07 10:52:19 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char	*s;
	int		neg_flag;
	int		n_curr;
	int		digit;

	digit = 1;
	n_curr = n;
	while ((unsigned)n_curr - 10 <= (unsigned)-20)
	{
		n_curr /= 10;
		digit++;
	}
	neg_flag = n < 0;
	s = malloc(sizeof(char) * (digit + neg_flag + 1));
	if (!s)
		return (NULL);
	s[digit + neg_flag] = '\0';
	while (digit)
	{
		s[digit-- + neg_flag - 1] = (((-neg_flag ^ (n % 10)) + neg_flag) + '0');
		n /= 10;
	}
	if (neg_flag)
		s[0] = '-';
	return (s);
}
