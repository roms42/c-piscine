/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 15:29:56 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/23 12:31:36 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//char	*ft_strdup(char *src);
//int		*ft_range(int min, int max);
int	ft_ultimate_range(int **range, int min, int max);

int main(int argc, char **argv)
{
	(void)(argc);

	//ex00
	//printf("ex 00:    ma fonction: %s\n", ft_strdup(argv[1]));
	//printf("ex 00: vraie fonction: %s\n\n", strdup(argv[1]));

	//ex01	
	/*int i = 0;
	int *tab;
	tab = ft_range(atoi(argv[1]), atoi(argv[2]));
	while (tab[i])
	{
		printf("%d ", tab[i]);
		i++;
	}*/
	
	//ex02
	/*int i = 0;
	int j = 0;
	int **range;
	ft_ultimate_range(range, atoi(argv[1]), atoi(argv[2]));
	while (range[0])
	{
		j = 0;
		while (range[0][j])
		{
			printf("%d", range[0][j]);
			j++;
		}
		i++;
	}*/

	//ex03
	char **strs;
	strs = argv[1];
	ft_strjoin(argc, strs...)

	
}
