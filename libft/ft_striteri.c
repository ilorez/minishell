/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: znajdaou <znajdaou@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 15:32:04 by znajdaou          #+#    #+#             */
/*   Updated: 2024/11/03 12:43:51 by znajdaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}

/*void _ft_toupper(unsigned int i, char *c)
{
  if (i % 2)
		*c -= 32;
}
int	main(int ac, char **av)
{
  if (ac == 3){
	ft_striteri(av[1], _ft_toupper);
		printf("%s\n", av[1]);

	ft_striteri(av[2], NULL);
	ft_striteri(NULL, _ft_toupper);
		printf("when str null or funtion pointer null: %s\n", av[2]);
  }
  return (0);
}*/
