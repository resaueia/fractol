/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 16:39:11 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/28 19:04:14 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int ac, char **argv)
{
	t_fractal	fractal;

	if (2 == ac && !ft_strncmp(argv[1], "mandelbrot", 10)
		|| 4 == ac && !ft_strncmp(argv[1], "julia", 5))
	{
		fractal.name = argv[1];
		if (!ft_strncmp(fractal.name, "julia", 5))
		{
			fractal.julia_x = atodbl(argv[2]);
			fractal.julia_y = atodbl(argv[3]);
		}
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_connection);
	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
	return (0);
}
