/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:33:16 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/28 16:32:03 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str);
int		ft_atoi_base(char *str, char *base);

int		ft_checkbase(char *str)
{
	int i;
	int j;
	int strlen;

	strlen = ft_strlen(str);
	i = 0;
	if (strlen == 1)
		return (0);
	while (str[i])
	{
		if (str[i] == '-' || str[i] == '+' || str[i] < 33 || str[i] > 126)
			return (0);
		j = i + 1;
		while (str[j])
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_putnbr_base(int nbr, char *base, char *dest)
{
	int blen;
	int k;

	k = 0;
	blen = ft_strlen(base);
	if (nbr < 0)
		nbr = -nbr;
	while (k < blen)
	{
		dest[k] = base[nbr % blen];
		nbr = nbr / blen;
		k++;
	}
}

void	ft_str_rev(char *dest)
{
	char	tmp;
	int		i;
	int		destlen;

	destlen = ft_strlen(dest);
	i = 0;
	if (destlen > 0)
	{
		while (i < destlen / 2)
		{
			tmp = dest[i];
			dest[i] = dest[destlen - 1 - i];
			dest[destlen - 1 - i] = tmp;
			i++;
		}
	}
}

int		ft_sizeofdest(int nb, int btolen)
{
	int k;
	int i;
	int j;

	i = 1;
	j = 0;
	if (nb < 0)
	{
		k = -nb;
	}
	else
		k = nb;
	while (i < k)
	{
		i = i * btolen;
		j++;
	}
	if (nb <= 0)
		j += 1;
	return (j);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*dest;
	int		j;
	int		btolen;
	int		nb;

	if (!(ft_checkbase(base_from)) || !(ft_checkbase(base_to)))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	btolen = ft_strlen(base_to);
	j = ft_sizeofdest(nb, btolen);
	if (!(dest = (char*)malloc(sizeof(char*) * (j + 1))))
		return (NULL);
	ft_putnbr_base(nb, base_to, dest);
	if (nb < 0)
		dest[j - 1] = '-';
	if (j == 0)
		j++;
	dest[j] = '\0';
	ft_str_rev(dest);
	dest[j] = '\0';
	return (dest);
}
