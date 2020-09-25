/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:53:12 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 15:22:25 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int ft_countwords(char *str, char *charset)
{
    int i;
    int j;
    int count;

    i = 0;
    j = 0;
    count = 0;
	while (str[i++])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		if (j != ft_strlen(charset))
			count++;
		i++;
	}
	count = count - 1;
	return (count);
}

char	**ft_init_tab(char *str, int count)
{
	int j;
	char **tab;
	int strlen;

	j = 0;
	strlen = ft_strlen(str);
	if (!(tab = (char**)malloc(sizeof(char*) * count)))
		return (NULL);
	while (count > 0)
	{
		if(!(tab[j] = (char*)malloc(sizeof(char) * strlen)))
			return (NULL);
		j++;
		count--;
	}
	return (tab);
}

char **ft_split(char *str, char *charset)
{
	int i;
	int j;
	int count;
	char **tab;
	int k;
	int l;

	i = 0;
	j = 0;
	l = 0;
	if (str[i] != '\0' && charset[j] != '\0')
	{
		count = ft_countwords(str, charset);
		tab = ft_init_tab(str, count);
		while (count > 0)
		{
			while (str[i++])
			{
				k = 0;
				j = 0;
				while (charset[j] && str[i] != charset[j])
					j++;
				if (j != ft_strlen(charset))
					tab[l][k++] = str[i];
				else
					break;
			}
			l++;
			count--;
			printf("count = %d\n", count);
			printf("tab[%d] = %s\n", l - 1, tab[l-1]);
		}
		printf("tab[%d] = %s", l - 1, tab[l-1]);
		tab[ft_countwords(str, charset)] = 0;
		return (tab);
	}
	return(0);
}

int main()
{
	//printf("%d\n", ft_countwords("boooonjjjour les copain hola", "oa"));
	char **tab;
	int i;

	i = 0;
	tab = ft_split("boooonjjjour les copain hola", "oa");
	tab = ft_split("", "o");

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
