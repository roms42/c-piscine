/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rberthau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 17:05:53 by rberthau          #+#    #+#             */
/*   Updated: 2020/09/30 17:16:31 by rberthau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//EX00
void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long i;

	i = nb;
	if (i < 0)
	{
		i = -i;
		ft_putchar('-');
	}
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
}

void	ft_plus(int a)
{
	int res;

	res = a + 10;
	ft_putnbr(res);
	ft_putchar('\n');
}


int main()
{
	void(*f)(int);
	int tab[4];

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	f = &ft_plus;
	ft_foreach(tab, 4, f);
}

//EX01
int	ft_plus(int a)
{
	int res;

	res = a + 10;
	return (res);
}

#include <stdio.h>
#include <stdlib.h>
int main()
{
	int tab[4];
	int(*f)(int);
	f = &ft_plus;
	int i = 0;
	int *tab3;

	tab[0] = 1;
	tab[1] = 2;
	tab[2] = 3;
	tab[3] = 4;
	tab3 = ft_map(tab, 4, f);
	while (i < 4)
	{
		printf("%d\n", tab3[i]);
		i++;
	}
}

//EX02
int ft_ismore(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (i)
		return (1);
	return (0);
}

#include <stdio.h>

int main()
{
	int(*f)(char*);
	int res;
	char *tab[5];

	tab[0] = "";
	tab[1] = "";
	tab[2] = "i";
	tab[3] = "";
	tab[4] = 0;
	f = &ft_ismore;
	res = ft_any(tab, f);
	printf("%d\n", res);

}

//EX03

int ft_ismore(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	if (i)
		return (1);
	return (0);
}

#include <stdio.h>

int main()
{
	int(*f)(char*);
	int res;
	char *tab[5];

	tab[0] = "";
	tab[1] = "i";
	tab[2] = "i";
	tab[3] = "";
	tab[4] = 0;
	f = &ft_ismore;
	res = ft_count_if(tab, 4, f);
	printf("%d\n", res);
}

//EX04
int ft_comp(int a, int b)
{
	if (a == b)
		return (0);
	return (a - b);
}

#include <stdio.h>

int main()
{
	int tab[4];

	tab[0] = -5;
	tab[1] = 4;
	tab[2] = 4;
	tab[3] = -10;
	int(*f)(int, int);
	f = &ft_comp;
	printf("%d\n", ft_is_sort(tab, 4, f));
}

//EX06
#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	ft_sort_string_tab(av);
	int a = ac;
	while (ac--)
		printf("%s\n", av[a - ac -1]);
}

//EX07

int ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	if (ft_strlen(s1) >= ft_strlen(s2))
		return (1);
	return (0);
}

#include <stdio.h>
#include <stdlib.h>
int main(int ac, char **av)
{
	(void)(ac);
	int (*f)(char*, char*);
	f = &ft_strcmp;
	ft_advanced_sort_string_tab(av, f);

	int i = -1;
	while (++i < ac)
		printf("%s\n", av[i]);
}
