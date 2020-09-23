/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 19:50:52 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/24 00:49:18 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

/*void	ft_gotofirst(char *str, char *charset)
{
	int j;

	while (*str && str[-1] != charset[j])
	{
		j = 0;
		while (charset[j] && *str != charset[j])
			j++;
		*str++;
	}
}*/

int	ft_gotonext(char *str, char *charset, int i)
{
	int j; 

	while (str[i] && str[i] == charset[j])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		i++;
	}
	return (i);
}

int	ft_gothrough(char *str, char *charset, int i)
{
	int j;
	int k;

	j = 0;
	k = 0;
	while (str[i] && str[i - 1] != charset[j])
	{
		j = 0;
		while (charset[j] && str[i] != charset[j])
			j++;
		i++;
		k++;
	}
	return (k);
}

int	ft_countwords(char *str, char *charset)
{
	int i;
	int j;
	int count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (i == 0)
		{
			j = 0;
			while (*str && str[-1] != charset[j])
			{
				j = 0;
				while (charset[j] && *str != charset[j])
					j++;
				str++;
			}
		}
		i = i + ft_gotonext(str, charset, i);
		j = ft_gothrough(str, charset, i);
		i = i + j;
		count++;
	}
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
	if(!(tab = (char**)malloc(sizeof(int) * count)))
		return (NULL);
	i = ft_gotonext(str, charset, i);
	while (count > 0)
	{
		k = ft_gothrough(str, charset, i) + 1;
		i = i + k;
		if(!(tab[j] = (char*)malloc(sizeof(char) * k)))
			return (NULL);
		i = i + ft_gotonext(str, charset, i);
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
		i = i + ft_gotonext(str, charset, i);
		k = ft_gothrough(str, charset, i);
		while (j <= k)
		{
			tab[countbis - count][j] = str[i];
			i++;
			j++;
			tab[countbis - count][j] = '\0';
		}
		count--;
	}
	tab[count] = 0;
	return (tab);
}

#include <stdio.h>

int main()
{
	char **tab;
	int i;
	
	i = 0;
	tab = ft_split("boooonjjjour les copain hola", "oa");
	while (tab[i])
	{
		printf("%s", tab[i]);
		i++;
	}
}
