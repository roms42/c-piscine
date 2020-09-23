/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:27:39 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/22 15:42:09 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int 	i;
	int 	j;
	char 	*dest;
	
	i = 0;
	while (src[i])
	{
		i++;
	}
	dest = (char*)malloc(sizeof(*src) * i + 1);
	if (!(dest))
		return (0);
	j = 0;
	while (j <= i)
	{
		dest[j] = src[j];
		j++;
	}
	dest[j] = '\0';
	return (dest);
}
