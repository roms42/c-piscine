/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:59:35 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/13 14:18:34 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_ultimate_div_mod(int *a, int *b)
{
	int c;

	c = *a;
	*a = c / *b;
	*b = c % *b;
}

int	main()
{
	int a;
	int b;
	a = 1;
	b = 4;
	printf("%d %d\n", a, b);
	ft_ultimate_div_mod(&a, &b);
	printf("%d %d", a, b);
}
