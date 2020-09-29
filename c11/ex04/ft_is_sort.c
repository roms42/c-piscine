/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 15:20:36 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/29 15:36:49 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int i;
	int result;
	int cmp;

	i = 0;
	result = (*f)(tab[i], tab[i + 1]);
	i++;
	while (i++ < length - 1)
	{
		cmp = (*f)(tab[i], tab[i + 1]);
		if (cmp != result && cmp != 0)
			return (0);
	}
	return (1);
}
