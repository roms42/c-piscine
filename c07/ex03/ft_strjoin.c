/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:43:43 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 00:26:03 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int i;

	i= 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}

int ft_sizeofdest(char **strs)
{
	int i;
	int j;
	int destlen;

	i = 0;
	destlen = 0;
	while (size > 0)
	{
		j = 0;
		while (strs[i][j])
		{
			j++;
			destlen++;
			size--;
		}
		i++;
	}
	return (destlen);
}

char	*ft_assigndest(int size, char *strs)
{
	int i;
	int j;:
	int k;
	char *dest;
	
	while (size > 0)
	{
		j = 0;
		while(strs[i][j++])
		{
			dest[k] = strs[i][j];
			k++;
		}
		j = 0;
		while (sep[j++])
		{
			dest[k] = sep[j];
			k++;
		}
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *dest;
	int seplen;
	int destlen;

	if (size == 0)
	{
		*strs = NULL;
		return (*strs);
	}
	seplen = ft_srtrlen(sep);
	destlen = ft_sizeofdest(strs);
	if(!(dest = (char*)malloc(sizeof(char) * (destlen + seplen * (size - 1))))
			return (NULL);
	dest = ft_assigndest(size, strs);
	return (dest);
}
