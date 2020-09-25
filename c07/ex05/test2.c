/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 14:12:35 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 14:54:07 by rberthau         ###   ########.fr       */
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

char	*ft_gotofirst(char *str, char *charset)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (*str++ && *str != charset[j])
	{
		j = 0;
		while (charset[j] && *str != charset[j])
		{
			j++;
		}
	}
	return (str);
}

int ft_countwords(char *str, char *charset)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0)
			str = ft_gotofirst(str, charset);
		while (str[i++])
			{
				j = 0;
				while (charset[j] && str[i] != charset[j])
					j++;
				if (j != ft_strlen(charset))
					count++;
				i++;
			}
	}
	return (count);
}

char	**ft_init_tab(char *str, char *charset, int count)
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
	int count;
	char **tab;
	int k;

	i = 0;
	j = 0;
	if (str[i] != '\0' && charset[j] != '\0')
	{
		count = ft_countwords(str, charset);
		tab = ft_init_tab(str, charset, count);
		
	}
}

int main()
{
	printf("%d\n", ft_countwords("boooonjjjour les copain hola", "oa"));
	/*char **tab;
	int i;

	i = 0;
	tab = ft_split("boooonjjjour les copain hola", "oa");
	tab = ft_split("", "o");

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}*/
}
