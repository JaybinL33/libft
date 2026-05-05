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
	int		digit;
	int		neg_flag;

	digit = 1;
	neg_flag = n < 0;
	while ((unsigned)n - 10 <= (unsigned)-20)
	{
		s[11 - digit] = (((-neg_flag ^ (n % 10)) + neg_flag) + '0');
		n /= 10;
		digit++;
	}
	s[11 - digit] = (((-neg_flag ^ n) + neg_flag) + '0');
	if (neg_flag)
		s[11 - ++digit] = '-';
	if (write(fd, s + 11 - digit, digit) == -1)
		return ;
}
