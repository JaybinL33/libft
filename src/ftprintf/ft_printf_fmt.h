/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fmt.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:40:13 by jungblee          #+#    #+#             */
/*   Updated: 2026/06/22 14:40:13 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_FMT_H
# define FT_PRINTF_FMT_H
# include <stdarg.h>

void	printf_format(char **start, char **end, va_list *ap, int spec);

#endif
