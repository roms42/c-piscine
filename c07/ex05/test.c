/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:20:40 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 16:50:03 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

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

int ft_gotonext(char *str, char *charset, int i)
{
	int j;

	j = 0;
	while (str[i++])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		if (j == 2)
			break;
	}
	return (i);
}

int	ft_gothrough(char *str, char *charset, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[i] && str[i++] != charset[j])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		k++;
	}
	return (k);
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
		i = ft_gotonext(str, charset, i);
		j = ft_gothrough(str, charset, i);
		i = i + j;
		count++;
	}
	count = count - 1;
	return (count);
}

char **ft_init_tab(char *str, char *charset, int count)
{
	int i;
	int j;
	int k;
	char **tab;

	i = 0;
	j = 0;
	if(!(tab = (char**)malloc(sizeof(char*) * count)))
		return (NULL);
	i = ft_gotonext(str, charset, i);
	while (count > 0)
	{
		k = ft_gothrough(str, charset, i) + 1;
		i = i + k;
		if(!(tab[j] = (char*)malloc(sizeof(char) * k)))
			return (NULL);
		i = ft_gotonext(str, charset, i);
		j++;
		count--;
	}
	return (tab);
}


char	**ft_split(char *str, char *charset)
{
	int i;
	int j;
	char **tab;
	int count;
	int countbis;
	int k;

	i = 0;
	j = 0;
	count = ft_countwords(str, charset);
	countbis = count;
	tab = ft_init_tab(str, charset, count);

	while (count > 0)
	{
		j = 0;
		i = ft_gotonext(str, charset, i);
		k = ft_gothrough(str, charset, i);
		while (j < k)
			tab[countbis - count][j++] = str[i++];
		tab[countbis - count][j] = '\0';
		count--;
	}
	tab[countbis] = NULL;
	return (tab);
}

#include <stdio.h>

int main()
{
	char **tab;
	int i;

	i = 0;
	//tab = ft_split("boooonjjjour les copain hola", "oa");
	tab = ft_split("", "o");

	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}
