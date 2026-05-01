/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/15 16:59:36 by jungblee          #+#    #+#             */
/*   Updated: 2026/06/22 09:37:02 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "ft_printf_fmt.h"
#include "ft_printf_io.h"
#include <limits.h>
#include <stdarg.h>
#include <stdint.h>
#include <unistd.h>

static int	printf_core(const char *__restrict *format, t_file *f, va_list *ap);

int	ft_printf(const char *__restrict format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = ft_vdprintf(STDOUT_FILENO, format, ap);
	va_end(ap);
	return (count);
}

int	ft_dprintf(int fd, const char *__restrict format, ...)
{
	int		count;
	va_list	ap;

	va_start(ap, format);
	count = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (count);
}

int	ft_vdprintf(int fd, const char *__restrict format, va_list ap)
{
	int		count;
	int		len;
	t_file	f;
	va_list	ap2;

	va_copy(ap2, ap);
	io_init(fd, &f);
	count = 0;
	while (*format)
	{
		len = printf_core(&format, &f, &ap2);
		if (len > INT_MAX - count || len < 0)
		{
			count = -1;
			break ;
		}
		count += len;
	}
	if (io_flush(&f) < 0)
		count = -1;
	va_end(ap2);
	return (count);
}

// Writes one chunk: a plain run up to the next conversion, or one
// rendered directive. The second loop folds each "%%" into the run,
// keeping only one of its two '%'.
// buf: one value byte takes under 3 decimal digits (log10 256 ~ 2.41),
// so 3 * sizeof holds any integer, with room left over for '-' and "0x".
static int	printf_core(const char *__restrict *format, t_file *f, va_list *ap)
{
	char	*start;
	char	*end;
	char	buf[sizeof(uintmax_t) * 3];
	int		len;

	start = (char *)*format;
	while (**format && **format != '%')
		(*format)++;
	end = (char *)*format;
	while ((*format)[0] == '%' && (*format)[1] == '%')
	{
		end++;
		*format += 2;
	}
	len = (int)(end - start);
	if (!len)
	{
		end = buf + sizeof(buf);
		printf_format(&start, &end, ap, (*format)[1]);
		*format += 2;
		len = (int)(end - start);
	}
	if (io_write(f, start, len) < 0)
		return (-1);
	return (len);
}
