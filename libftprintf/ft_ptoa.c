/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sohan <sohan@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/28 21:17:07 by sohan             #+#    #+#             */
/*   Updated: 2021/09/28 21:17:13 by sohan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	find_digit_p(unsigned long long int n, int base)
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

char	*ft_ptoa(unsigned long long int n, char *base)
{
	unsigned long long int	init;
	int						digit;
	char					*nbr;

	init = n;
	digit = find_digit_p(n, ft_strlen(base));
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
	return (nbr);
}
