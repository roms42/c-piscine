/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 12:54:22 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/13 14:10:55 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}

int	main()
{
	int a;
	int b;
	int div;
	int mod;

	a = 1;
	b = 4;
	printf("%d %d\n", a, b);
	ft_div_mod(a, b, &div, &mod);
	printf("%d %d", div, mod);
}
