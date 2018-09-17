/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzungula <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/26 13:04:34 by yzungula          #+#    #+#             */
/*   Updated: 2018/08/19 17:48:58 by yzungula         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	len;
	char	*new_str;

	i = -1;
	j = -1;
	len = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2)
		return (NULL);
	new_str = (char *)malloc(sizeof(char) * (len + 1));
	if (new_str)
	{
		while (s1[++i] != '\0')
			new_str[i] = s1[i];
		while (s2[++j] != '\0')
			new_str[i + j] = s2[j];
		new_str[i + j] = '\0';
		return (new_str);
	}
	return (NULL);
}
