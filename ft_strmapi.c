/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jungblee <jungblee@student.42gyeongsan.kr> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/07 13:13:23 by jungblee          #+#    #+#             */
/*   Updated: 2026/05/07 13:13:23 by jungblee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	size_t	len;
	char	*mapped_s;

	len = ft_strlen(s);
	if (len > (unsigned)-1)
		len = (unsigned)-1;
	i = 0;
	mapped_s = malloc(sizeof(char) * (len + 1));
	if (!mapped_s)
		return (NULL);
	while (i <= (unsigned)-1 && s[i])
	{
		mapped_s[i] = f(i, s[i]);
		i++;
	}
	mapped_s[i] = '\0';
	return (mapped_s);
}
