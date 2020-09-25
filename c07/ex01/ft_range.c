/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:22:48 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/25 13:04:31 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int i;
	int j;

	i = max - min;
	if (!(tab = (int*)malloc(sizeof(*tab) * i)) || min >= max)
		return (NULL);
	j = 0;
	while (min < max)
	{
		tab[j] = min;
		min++;
		j++;
	}
	return (tab);
}

#include <stdio.h>

int main(int ac, char **argv)
{
	(void)(ac);
	int i = 0;
	int *tab;
	tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}
}
