/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aet-tass <aet-tass@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/19 18:33:25 by aet-tass          #+#    #+#             */
/*   Updated: 2023/02/23 14:47:58 by aet-tass         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"


#include <stdio.h>
#include <stdlib.h>


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\v' || str[i] == '\f'
		|| str[i] == '\t' || str[i] == '\r')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] != '\0' && str[i] >= '0' && str[i] <= '9')
	{
		res *= 10;
		res = (res + str[i]) - '0';
		i++;
	}
	return (res * sign);
}


float float_atoi(const char *str)
{
    float result = 0.0;
    int sign = 1;
    int fraction = 0;
    float fraction_value = 1;

	while (*str == ' ' || *str == '\n' || *str == '\v' || *str == '\f'
		|| *str == '\t' || *str == '\r')
		str++;
     if (*str == '-') {
         sign = -1;
         str++;
     }

     while (*str >= '0' && *str <= '9') {
         result = result * 10.0 + (*str - '0');
         str++;
     }

    /* Parse fractional part */
    if (*str == '.') {
        str++;

        while (*str >= '0' && *str <= '9') {
            fraction = fraction * 10 + (*str - '0');
            fraction_value *= 0.1;
            str++;
        }

        result += fraction * fraction_value;
    }

    return sign * result;
}
