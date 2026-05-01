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

static int	ft_get_len(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 10)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		is_neg;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	is_neg = (n < 0);
	if (is_neg)
		n = -n;
	len = ft_get_len(n);
	s = malloc(sizeof(char) * (len + is_neg + 1));
	if (!s)
		return (NULL);
	s[len + is_neg] = '\0';
	if (is_neg)
		s[0] = '-';
	while (len--)
	{
		s[len + is_neg] = (n % 10) + '0';
		n /= 10;
	}
	return (s);
}
