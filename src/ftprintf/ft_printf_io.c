/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_io.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:39:35 by jungblee          #+#    #+#             */
/*   Updated: 2026/06/22 14:39:35 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_io.h"
#include "ftcustom.h"
#include "ftstring.h"
#include <stdio.h>
#include <unistd.h>

void	io_init(int fd, t_file *f)
{
	f->fd = fd;
	f->len = 0;
}

int	io_flush(t_file *f)
{
	int	ret;

	ret = (int)ft_putnstr_fd(f->buf, f->fd, f->len);
	f->len = 0;
	return (ret);
}

int	io_write(t_file *f, const char *s, size_t len)
{
	size_t	i;

	i = len;
	while (i && s[i - 1] != '\n')
		i--;
	if (i)
	{
		if (io_flush(f) < 0 || ft_putnstr_fd(s, f->fd, i) < 0)
			return (-1);
		s += i;
		len -= i;
	}
	if (len > BUFSIZ - f->len)
	{
		if (io_flush(f) < 0 || ft_putnstr_fd(s, f->fd, len) < 0)
			return (-1);
		return (0);
	}
	ft_memcpy(f->buf + f->len, s, len);
	f->len += len;
	return (0);
}
