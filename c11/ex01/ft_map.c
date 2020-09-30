/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:23:15 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 16:07:13 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int i;
	int *tab2;

	if(!(tab2 = malloc(sizeof(int) * length)))
		return (NULL);
	i = 0;
	while (i < length)
	{
		tab2[i] = (*f)(tab[i]);
		i++;
	}
	return (tab2);
}

int	ft_plus(int a)
{
	int res;

	res = a + 10;
	return (res);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int tab[4];
	int(*f)(int);
	f = &ft_plus;
	int i = 0;
	int *tab3;

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab3 = ft_map(tab, 4, f);
	while (i < 4)
	{
		printf("%d\n", tab3[i]);
		i++;
	}
}
