/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:43:26 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/07 15:43:26 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	s[11];
	int		i;
	int		neg;

	if (n == -2147483648)
	{
		if (write(fd, "-2147483648", 11) == -1)
			return ;
		return ;
	}
	i = 11;
	neg = n < 0;
	if (neg)
		n = -n;
	if (n == 0)
		s[--i] = '0';
	while (n)
	{
		s[--i] = (n % 10) + '0';
		n /= 10;
	}
	if (neg)
		s[--i] = '-';
	write(fd, s + i, 11 - i);
}
