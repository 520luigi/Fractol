/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:31:23 by szheng            #+#    #+#             */
/*   Updated: 2018/11/05 23:01:49 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

/*
** This function just prints out the usage if the user enters a false number,
** too many inputs, or any other characters.
*/

void	ft_print_usage(void)
{
	ft_putstr("Usage: ./fractol [fractol number]\n\n");
	ft_putstr("1 - Mandelbrot Set\n");
	ft_putstr("2 - Julia Set\n");
	ft_putstr("3 - Burning Ship Set\n");
	ft_putstr("4 - Tricorn Set\n");
	exit(0);
}

/*
** This function prints the instructions onto the top left side of the window.
*/

void	print_instructions(t_mlx *m)
{
	mlx_string_put(m->mlx, m->win, 8, 0, 0xFF0000,
		"Hide Instructions > i");
	mlx_string_put(m->mlx, m->win, 8, 15, 0xFF0000, "Zoom > mouse wheel");
	mlx_string_put(m->mlx, m->win, 8, 30, 0xFF0000,
		"Move > mouse click");
	mlx_string_put(m->mlx, m->win, 8, 45, 0xFF0000,
		"Change iteration > - + ");
	mlx_string_put(m->mlx, m->win, 8, 60, 0xFF0000, "Change color palette > c");
	mlx_string_put(m->mlx, m->win, 8, 75, 0xFF0000, "Shift > arrow keys");
	mlx_string_put(m->mlx, m->win, 8, 90, 0xFF0000,
		"Change Fractols > 1 2 3 4");
	mlx_string_put(m->mlx, m->win, 8, 105, 0xFF0000, "Pause Julia Set > p");
	mlx_string_put(m->mlx, m->win, 8, 120, 0xFF0000, "Reset > r");
}

void	draw(t_mlx *m)
{
	m->draw.y = -1;
	while (++(m->draw.y) < HEIGHT)
	{
		m->draw.x = -1;
		while (++(m->draw.x) < WIDTH)
		{
			m->draw.index = ((HEIGHT - (m->draw.y + 1)) * WIDTH + m->draw.x);
			m->draw.i = display_fractal(m);
			if (m->draw.i <= m->max_iter)
				((unsigned int *)m->img.str)[m->draw.index] =
				m->color.palette[(m->draw.i) % 16];
			else
				((unsigned int *)m->img.str)[m->draw.index] = 0;
		}
	}
	mlx_put_image_to_window(m->mlx, m->win, m->img.ptr, 0, 0);
	if (m->hide == 1)
		print_instructions(m);
}
