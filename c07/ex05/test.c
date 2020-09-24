/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:20:40 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/24 14:42:38 by rberthau         ###   ########.fr       */
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
		printf("str = %c \n", *str);
		j = 0;
		while (charset[j] && *str != charset[j])
		{
			j++;
			printf("charset[%d] = %c \n", j, charset[j]);
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
		printf("j = %d\n", j);
		if (j == 2)
			break;
	}
	printf("i = %d\n", i);
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
		{
			str = ft_gotofirst(str, charset);
		}
		i = ft_gotonext(str, charset, i);
		printf("after gotonext str[%d] = %c\n", i, str[i]);
		j = ft_gothrough(str, charset, i);
		i = i + j;
		count++;
		printf("after gothrough str[%d] = %c\n", i, str[i]);
	}
	count = count - 1;
	printf("count = %d\n", count);
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
	printf("str[%d] = %c \n", i, str[i]);
	tab = ft_init_tab(str, charset, count);
	while (count > 0)
	{
		j = 0;
		i = ft_gotonext(str, charset, i);
		k = ft_gothrough(str, charset, i);
		while (j < k)
		{
			tab[countbis - count][j] = str[i];
			i++;
			j++;
			tab[countbis - count][j] = '\0';
		}
		printf("tab[%d] = %s\n", countbis - count, tab[countbis - count]);
		count--;
	}
	tab[countbis] = 0;
	return (tab);
}

/*char *ft_split(char *str, char *charset)
{
	int i;
	int j;
	int count;

	i = 0;
	j = 0;
	str = ft_gotofirst(str, charset);
	printf("str[0] = %c, str[1] = %c, str[2] = %c, str[3] = %c \n", str[0], str[1], str[2], str[3]);
	i = i + ft_gotonext(str, charset, i);
	printf("i = %d and str[%d] = %c\n", i, i, str[i]);
	j = ft_gothrough(str, charset, i);
	i = i + j;
	printf("i = %d and str[%d] = %c\n", i, i, str[i]);
	printf("str[i] = %c, str[i+1] = %c, str[i+2] = %c, str[i+3] = %c \n", str[i], str[i+1], str[i+2], str[i+3]);
	count = ft_countwords(str, charset);
	printf("count = %d\n", count);
	return (str);
}*/

#include <stdio.h>

int main()
{
	char **tab;
	int i;

	i = 0;
	tab = ft_split("boooonjjjour les copain hola", "oa");
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		i++;
	}
}

/*#include <stdio.h>

int main()
{
	char *str = "boooonjjjour les copain hola";
	char *charset = "oa";
	str = ft_split(str, charset);
	int i;
	i = 0;
	while (str[i])
	{
		printf("str[%d] is = %c\n", i, str[i]);
		i++;
	}
}*/
