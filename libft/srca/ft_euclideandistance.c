/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_euclideandistance.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: daniel-da <daniel-da@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:41:32 by daniel-da         #+#    #+#             */
/*   Updated: 2025/04/10 01:41:34 by daniel-da        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

int	ft_euclideandistance(t_vector src, t_vector dest)
{
	return (ft_sqrt(ft_recursive_power(dest.x - src.x, 2) + \
							ft_recursive_power(dest.y - src.y, 2)));
}
