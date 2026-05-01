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

#include "ftcustom.h"
#include <unistd.h>

void	ft_putnbr_fd(int n, int fd)
{
	char	s[12];
	int		i;
	int		is_neg;

	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	is_neg = n < 0;
	if (is_neg)
		n = -n;
	i = 11;
	s[i] = '\0';
	if (!n)
		s[--i] = '0';
	while (n)
	{
		s[--i] = (char)((n % 10) + '0');
		n /= 10;
	}
	if (is_neg)
		s[--i] = '-';
	ft_putstr_fd(s + i, fd);
}
