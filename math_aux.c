/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_aux.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 17:12:08 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/28 19:09:39 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* UNDERSTAND MANDELBROT EQUATION
  z = z² + c -> this basically means that z1 is c + c;
  z is, initially, 0,0 while c is the actual point */

/* UNDERSTAND JULIA SET AND THE MATH BEHIND IT
  ./fractol julia <real_value> <imaginary_value>
  z = pixel_point + constant;
*/

double map(double unscaled_num, double new_min, double new_max, double old_min, double old_max)
{
    return (new_max - new_min) * (unscaled_num - old_min) / (old_max - old_min) + new_min;
}

t_complex   sum_complex(t_complex z1, t_complex z2)
{
    t_complex   result;

    result.x = z1.x + z2.x;
    result.y = z1.y + z2.y;
    return result;
}


/*
 * SQUARE is trickier
 *
 * real = (x^2 - y^2)
 * i =  2*x*y
*/
t_complex   square_complex(t_complex z)
{
    t_complex   result;
    
    result.x = (z.x * z.x) - (z.y * z.y);
    result.y = 2 * z.x * z.y;
    return result;
}
