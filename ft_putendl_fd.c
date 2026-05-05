/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   <                                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 15:42:04 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/07 17:35:48 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

void	ft_putendl_fd(char *s, int fd)
{
	if (write(fd, s, ft_strlen(s)) == -1 || write(fd, "\n", 1) == -1)
		return ;
}
