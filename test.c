/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arguilla <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 02:27:49 by arguilla          #+#    #+#             */
/*   Updated: 2020/09/30 18:39:24 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int i;
	int check_asc;
	int check_desc;

	check_desc = 1;
	check_asc = 1;
	i = -1;
	while (++i + 1 < length)
		if ((*f)(tab[i], tab[i + 1]) > 0)
			check_asc = 0;
	i = length;
	while (--i > 0)
		if ((*f)(tab[i], tab[i - 1]) > 0)
			check_desc = 0;
	return (check_asc + check_desc >= 1);
}
