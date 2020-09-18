/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 21:52:15 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/11 12:21:36 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int j;
	int tmp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
			}
			j++;
		}
		i++;
	}
}

int main(void)
{
	int    tab[6] = {12, 24, -42, 0, 0, 20000};

	printf("07 : [%d, %d, %d, %d, %d, %d] | ", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]); ft_sort_int_tab(tab, 6);
	printf("[%d, %d, %d, %d, %d, %d]\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
}
