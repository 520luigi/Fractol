/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setup.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/29 15:26:53 by szheng            #+#    #+#             */
/*   Updated: 2018/11/06 14:49:23 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	setup(t_mlx *m)
{
	m->max_iter = 50;
	m->coor.min_x = -2;
	m->coor.max_x = 2;
	m->coor.min_y = -2;
	m->coor.max_y = 2;
	m->coor.scale_x = (m->coor.max_x - m->coor.min_x) / WIDTH;
	m->coor.scale_y = (m->coor.max_y - m->coor.min_y) / HEIGHT;
	m->julia.x = 0;
	m->julia.y = 0;
	m->mouse.x = 0;
	m->mouse.y = 0;
	m->julia.pause = 0;
	m->hide = 1;
	m->img.bpp = 32;
	m->img.size_line = 1 * WIDTH;
	m->img.endian = 1;
	m->color.index = 0;
	switch_colorset(m);
	m->img.str = mlx_get_data_addr(m->img.ptr, &(m->img.bpp),
			&(m->img.size_line), &(m->img.endian));
}

double	calc_draw_x(t_mlx *m)
{
	return (((m->coor.min_x + m->coor.max_x) / 2 +
			(m->draw.x - (double)WIDTH / 2) * m->coor.scale_x));
}

double	calc_draw_y(t_mlx *m)
{
	return (((m->coor.min_y + m->coor.max_y) / 2 -
			(m->draw.y - (double)HEIGHT / 2) * m->coor.scale_y));
}

double	calc_x(t_mlx *m, int x)
{
	return (((m->coor.min_x + m->coor.max_x) / 2 +
			(x - (double)WIDTH / 2) * m->coor.scale_x));
}

double	calc_y(t_mlx *m, int y)
{
	return (((m->coor.min_y + m->coor.max_y) / 2 -
			(y - (double)HEIGHT / 2) * m->coor.scale_y));
}
