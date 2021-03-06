/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:38:07 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 17:20:48 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (i < length)
	{
		if ((*f)(tab[i]))
			k++;
		i++;
	}
	return (k);
}
