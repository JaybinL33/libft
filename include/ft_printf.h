/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/19 17:41:22 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/19 17:52:18 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>

int	ft_printf(const char *__restrict format, ...);
int	ft_dprintf(int fd, const char *__restrict format, ...);

int	ft_vdprintf(int fd, const char *__restrict format, va_list ap);

#endif
