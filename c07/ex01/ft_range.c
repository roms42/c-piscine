/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:22:48 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/23 12:01:36 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*tab;
	int i;
	int j;

	i = max - min + 1;
	if (min >= max)
	{
		tab = NULL;
		return (tab);
	}
	if (!(tab = (int*)malloc(sizeof(*tab) * i)))
		return (NULL);
	j = 0;
	while (min < max)
	{
		tab[j] = min;
		min++;
		j++;
	}
	tab[j] = '\0';
	return (tab);
}
