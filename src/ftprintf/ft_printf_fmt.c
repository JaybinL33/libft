/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:40:03 by jungblee          #+#    #+#             */
/*   Updated: 2026/06/22 14:40:03 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_fmt.h"
#include "ftstring.h"
#include <stdarg.h>
#include <stdint.h>
#define LOWER 0x20

static char	*fmt_x(uintmax_t arg, char *end, int lower);
static char	*fmt_p(uintmax_t arg, char *end);
static char	*fmt_u(unsigned int arg, char *end);
static char	*fmt_i(int arg, char *end);

void	printf_format(char **start, char **end, va_list *ap, int spec)
{
	if (spec == 'd' || spec == 'i')
		*start = fmt_i(va_arg(*ap, int), *end);
	else if (spec == 'u')
		*start = fmt_u(va_arg(*ap, unsigned int), *end);
	else if ((spec | LOWER) == 'x')
		*start = fmt_x(va_arg(*ap, unsigned int), *end, spec & LOWER);
	else if (spec == 'p')
		*start = fmt_p((uintptr_t)va_arg(*ap, void *), *end);
	else if (spec == 'c')
	{
		*start = *end - 1;
		**start = (char)va_arg(*ap, int);
	}
	else if (spec == 's')
	{
		*start = va_arg(*ap, void *);
		if (!*start)
			*start = "(null)";
		*end = *start + ft_strlen(*start);
	}
}

// 'lower' is the ASCII case bit (0x20) taken from the spec char:
// OR-ing it turns A-F into a-f and leaves digits unchanged.
static char	*fmt_x(uintmax_t arg, char *end, int lower)
{
	const char	xdigits[17] = "0123456789ABCDEF";

	if (!arg)
		return (*--end = '0', end);
	while (arg)
	{
		*--end = (char)(xdigits[arg & 15] | lower);
		arg >>= 4;
	}
	return (end);
}

static char	*fmt_p(uintmax_t arg, char *end)
{
	if (!arg)
		return (ft_memcpy(end - 5, "(nil)", 5));
	return (ft_memcpy(fmt_x(arg, end, LOWER) - 2, "0x", 2));
}

static char	*fmt_u(unsigned int arg, char *end)
{
	if (!arg)
		return (*--end = '0', end);
	while (arg >= 10)
	{
		*--end = (char)('0' + (arg % 10));
		arg /= 10;
	}
	if (arg)
		*--end = (char)('0' + arg);
	return (end);
}

// The digit loop works on negative values (positives are negated
// first), so INT_MIN, which has no positive form, needs no special case.
static char	*fmt_i(int arg, char *end)
{
	int	neg;

	if (!arg)
		return (*--end = '0', end);
	neg = 1;
	if (arg > 0)
	{
		arg = -arg;
		neg = 0;
	}
	while (arg <= -10)
	{
		*--end = (char)('0' - (arg % 10));
		arg /= 10;
	}
	if (arg)
		*--end = (char)('0' - arg);
	if (neg)
		*--end = '-';
	return (end);
}
