/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:11:41 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/23 12:21:05 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int i;
	int j;
	int *tab;

	i = max - min;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	if(!(tab = (int*)malloc(sizeof(int) * i)))
		return (-1);
	j = 0;
	while (min < max)
	{
		tab[j] = min;
		min++;
		j++;
	}
	*range = tab;
	return (j);
}
