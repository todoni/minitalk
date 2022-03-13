/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/10 17:00:04 by sohan             #+#    #+#             */
/*   Updated: 2021/05/10 17:52:00 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_digit(int n, int base)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	while (n && base)
	{
		n /= base;
		digit++;
	}
	return (digit);
}

char	*ft_itoa(int n, char *base)
{
	int		init;
	int		digit;
	char	*nbr;

	init = n;
	digit = find_digit(n, ft_strlen(base));
	if (init < 0)
		digit++;
	nbr = (char *)ft_calloc(digit + 1, sizeof(char));
	if (nbr == 0)
		return (0);
	while (digit > 0)
	{
		if (init < 0)
			nbr[digit - 1] = base[-(n % ft_strlen(base))];
		else
			nbr[digit - 1] = base[n % ft_strlen(base)];
		n /= ft_strlen(base);
		digit--;
	}
	if (init < 0)
		nbr[0] = '-';
	return (nbr);
}
