/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_matrix_replace_in.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:42:29 by daniel-da         #+#    #+#             */
/*   Updated: 2025/04/10 01:42:31 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_matrix_replace_in(char ***big, char **small, int n)
{
	char	**aux;
	int		i[3];

	i[0] = -1;
	i[1] = -1;
	i[2] = -1;
	if (!big || !*big || n < 0 || n >= ft_matrixlen(*big))
		return (NULL);
	aux = ft_calloc(ft_matrixlen(*big) + ft_matrixlen(small), sizeof(char *));
	while (aux && big[0][++i[0]])
	{
		if (i[0] != n)
			aux[++i[2]] = ft_strdup(big[0][i[0]]);
		else
		{
			while (small && small[++i[1]])
				aux[++i[2]] = ft_strdup(small[i[1]]);
		}
	}
	ft_free_matrix(big);
	*big = aux;
	return (*big);
}
