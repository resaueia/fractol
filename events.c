/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsaueia- <rsaueia-@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/25 16:19:11 by rsaueia-          #+#    #+#             */
/*   Updated: 2024/03/28 19:40:28 by rsaueia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/*
 * ESC or i press the x🔴 in the window
 * there won't be leaks!
 * int (*f)(void *param)
*/
int	close_handler(t_fractal *fractal)
{
	mlx_destroy_image(fractal->mlx_connection, fractal->img.img_ptr);
	mlx_destroy_window(fractal->mlx_connection, fractal->mlx_window);
	mlx_destroy_display(fractal->mlx_connection);
	free(fractal->mlx_connection);
	exit(EXIT_SUCCESS);
}

/*
 * Keypress prototype
 * int (*f)(int keycode, void *param)
*/
int	key_handler(int keysym, t_fractal *fractal)
{
	if (keysym == XK_Escape)
		close_handler(fractal);
	if (keysym == XK_Left)
		fractal->shift_x += (0.5 * fractal->zoom);
	else if (keysym == XK_Right)
		fractal->shift_x -= (0.5 * fractal->zoom);
	else if (keysym == XK_Up)
		fractal->shift_y -= (0.5 * fractal->zoom);
	else if (keysym == XK_Down)
		fractal->shift_y += (0.5 * fractal->zoom);
	else if (keysym == XK_plus)
		fractal->iterations_definition += 10;
	else if (keysym == XK_minus)
		fractal->iterations_definition -= 10;
	fractal_render(fractal);
	return (0);
}

/***ZOOM***/

int	mouse_handler(int button, int x, int y, t_fractal *fractal)
{
	if (button == Button5)
	{
		fractal->zoom *= 0.95;
	}
	else if (button == Button4)
	{
		fractal->zoom *= 1.05;
	}
	fractal_render(fractal);
	return (0);
}

/*
 * TRACK the mouse
 * to change julia dynamically
 * int (*f)(int x, int y, void *param)
*/
int	julia_track(int x, int y, t_fractal *fractal)
{
	if (!ft_strncmp(fractal->name, "julia", 5))
	{
		fractal->julia_x = (map(x, -2, +2, WIDTH) * fractal->zoom) \
		+ fractal->shift_x;
		fractal->julia_y = (map(y, +2, -2, HEIGHT) * fractal->zoom) \
		+ fractal->shift_y;
		fractal_render(fractal);
	}
	return (0);
}
