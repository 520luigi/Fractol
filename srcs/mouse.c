/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/04 23:24:27 by szheng            #+#    #+#             */
/*   Updated: 2018/11/05 23:02:13 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

int	julia_mouse_tracker(int x, int y, t_mlx *m)
{
	m->mouse.x = x;
	m->mouse.y = y;
	if (m->mode_num == 1 && !m->julia.pause)
	{
		m->julia.x = calc_x(m, x);
		m->julia.y = calc_y(m, y);
		draw(m);
	}
	return (0);
}

int	deal_mouse(int button, int x, int y, t_mlx *m)
{
	if (button == 4 || button == 5)
	{
		m->coor.scale_x = m->coor.scale_x / ((button == 4) ? 1.5 : 0.9);
		m->coor.scale_y = m->coor.scale_y / ((button == 4) ? 1.5 : 0.9);
	}
	m->new_mid.x = calc_x(m, x);
	m->new_mid.y = calc_y(m, HEIGHT - y);
	m->mid.x = (m->coor.min_x + m->coor.max_x) / 2;
	m->mid.y = (m->coor.min_y + m->coor.max_y) / 2;
	m->coor.min_x -= (m->mid.x - m->new_mid.x);
	m->coor.max_x -= (m->mid.x - m->new_mid.x);
	m->coor.min_y -= (m->mid.y - m->new_mid.y);
	m->coor.max_y -= (m->mid.y - m->new_mid.y);
	draw(m);
	return (0);
}
