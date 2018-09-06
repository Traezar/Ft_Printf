/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setbit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsathiad <3kiraj@gmail.com>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/03 14:10:36 by rsathiad          #+#    #+#             */
/*   Updated: 2018/09/04 17:11:36 by rsathiad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

unsigned char	ft_setbit(char name, int position)
{
	unsigned int mask;

	mask = 0;
	mask = 1 << position;
	return (mask | name);
}
