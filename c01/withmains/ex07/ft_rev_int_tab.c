/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 16:16:39 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/10 20:09:14 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int tmp;
	int i;
	i = 0;
	size = size - 1;
	while (i <= size)
	{
		// [1, 2, 3, 4]
		tmp = tab[i]; // -> 1
		
		tab[i] = tab[size]; // -> tab[0] = 4
		
		tab[size] = tmp; // -> tab[3] = 1

		//*(tab + (c--)) = *(tab + size - c) 
		i++; // -> 1 
		size--; // -> 2
	}

	// 2 eme iteration
	while (i <= size) // i = 1
	{
		// [1, 2, 3, 4]
		tmp = tab[i]; // -> 2
		
		tab[i] = tab[size]; // -> tab[1] = 3
		
		tab[size] = tmp; // -> tab[2] = 2

		//*(tab + (c--)) = *(tab + size - c) 
		i++; // -> 1 
		size--; // -> 2
	}
}

int main()
{
	printf("%d", ft_rev_int_tab(42, 4));
}
