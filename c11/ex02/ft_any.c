/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 22:28:00 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/28 22:37:00 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int(*f)(char*))
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (tab[i])
	{
		if ((*f)(tab[i]))
			k++;
		i++;
	}
	if (k)
		return (1);
	return (0);
}