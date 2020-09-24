/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 16:22:48 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/24 22:56:15 by rberthau         ###   ########.fr       */
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
