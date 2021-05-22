/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jabilbo <jabilbo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/03 19:45:45 by jabilbo           #+#    #+#             */
/*   Updated: 2021/05/03 19:45:46 by jabilbo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

double	ft_pow(double x, double y)
{
	double	val;
	double	sign;

	if (y == 0)
		return (1.0);
	sign = (x < 0) ? -1.0 : 1.0;
	x = (x < 0) ? (-x) : (x);
	val = x;
	if (y < 0)
	{
		y = -y;
		while (--y > -2)
			val /= x;
	}
	else
	{
		while (--y > 0)
			val *= x;
	}
	return (val * sign);
}
