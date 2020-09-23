/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 09:43:43 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/23 17:48:27 by rberthau         ###   ########.fr       */
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

int ft_sizeofstrs(char **strs)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (strs[i])
	{
		while (strs[i][j])
			j++;
	}
	i++;
	return (j)
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char *dest;
	int i;
	int j;
	int k;
	int seplen;
	int 

	i = 0;
	if (size == 0)
	{
		*strs = NULL;
		return (*strs);
	}
	seplen = ft_srtrlen(sep);
	strslen = ;
	dest = (char*)malloc(sizeof(char*) * (strslen + seplen * (size - 1)));
	i = 0;
	k = 0;
	while (strs[i])
	{
		j = 0;
		while(strs[i][j])
		{
			dest[k] = strs[i][j];
			j++;
			k++;
		}
		i++;
	}
	return (dest);
}
