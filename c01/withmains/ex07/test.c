/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:59:22 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/10 21:50:47 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void ft_rev_int_tab(int *tab, int size)
{
	int tmp;
	int c;
	int d;

	c = size;
	d = size;
	while (c > (size / 2))
	{
		tmp = tab[c-1];
		tab[c - 1] = tab[size - d];
		tab[size - c] = tmp;
		c--;
		d--;
	}
}

int main()
{
	int    tab[6] = {12, 24, -42, 0, 0, 20000};
	 
	printf("07 : [%d, %d, %d, %d, %d, %d] | ", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]); ft_rev_int_tab(tab, 6);
	printf("[%d, %d, %d, %d, %d, %d]\n", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
}
