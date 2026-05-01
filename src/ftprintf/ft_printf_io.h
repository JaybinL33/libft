/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_io.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/22 14:39:49 by jungblee          #+#    #+#             */
/*   Updated: 2026/06/22 14:39:49 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_IO_H
# define FT_PRINTF_IO_H
# include <stdio.h>

typedef struct s_file
{
	unsigned char	buf[BUFSIZ];
	int				fd;
	size_t			len;
}					t_file;

void				io_init(int fd, t_file *f);
int					io_flush(t_file *f);
int					io_write(t_file *f, const char *s, size_t len);

#endif
