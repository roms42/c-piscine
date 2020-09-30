/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 12:23:18 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 15:40:34 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *))
{
	int i;
	int length;
	char *tmp;

	length = 0;
	while (tab[length])
	{
		i = 0;
		while (tab[i + 1])
		{
			if ((*cmp)(tab[i], tab[i + 1]) > 0)
			{
				tmp = tab[i];
				tab[i] = tab[i + 1];
				tab[i + 1] = tmp;
			}
			i++;
		}
		length++;
	}
}

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) >= ft_strlen(s2))
		return (1);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	(void)(ac);
	int (*f)(char*, char*);
	f = &ft_strcmp;
	ft_advanced_sort_string_tab(av, f);

	int i = -1;
	while (++i < ac)
		printf("%s\n", av[i]);
}
