/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:43:43 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 11:44:42 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int		ft_sizeofdest(int size, char **strs)
{
	int i;
	int j;
	int destlen;

	i = 0;
	destlen = 0;
	while (size-- > 0)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			destlen++;
		}
		i++;
	}
	return (destlen);
}

char	*ft_assigndest(int size, char *dest, char **strs, char *sep)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (size-- > 0)
	{
		j = 0;
		while (strs[i][j])
		{
			dest[k++] = strs[i][j++];
		}
		j = 0;
		while (sep[j])
		{
			dest[k++] = sep[j++];
		}
		i++;
	}
	dest[k] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*dest;
	int		seplen;
	int		destlen;

	if (size == 0)
	{
		**strs = '\0';
		return (*strs);
	}
	seplen = ft_strlen(sep);
	destlen = ft_sizeofdest(size, strs);
	if (!(dest = (char*)malloc(sizeof(char) * (destlen + seplen * (size - 1)))))
		return (NULL);
	dest = ft_assigndest(size, dest, strs, sep);
	return (dest);
}
