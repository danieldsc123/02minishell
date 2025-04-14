/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dup_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:41:24 by daniel-da         #+#    #+#             */
/*   Updated: 2025/04/10 01:41:25 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	**ft_dup_matrix(char **m)
{
	char	**out;
	int		n_rows;
	int		i;

	i = 0;
	n_rows = ft_matrixlen(m);
	out = malloc(sizeof(char *) * (n_rows + 1));
	if (!out)
		return (NULL);
	while (m[i])
	{
		out[i] = ft_strdup(m[i]);
		if (!out[i])
		{
			ft_free_matrix(&out);
			return (NULL);
		}
		i++;
	}
	out[i] = NULL;
	return (out);
}
