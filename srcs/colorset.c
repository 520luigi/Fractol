/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 18:33:11 by szheng            #+#    #+#             */
/*   Updated: 2018/11/06 14:44:10 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	color_set1(t_mlx *m)
{
	const int color_palette[16] = {
		0xa83018,
		0x481818,
		0x000000,
		0xf0a848,
		0xc04818,
		0xd86018,
		0xc06030,
		0x901800,
		0xf0c078,
		0xf0d890,
		0xd87830,
		0x180000,
		0xf09030,
		0x000018,
		0xc07848,
		0xd89048
	};

	m->color.palette = color_palette;
}

void	color_set2(t_mlx *m)
{
	const int color_palette[16] = {
		0x421E0F,
		0x19071A,
		0x09012F,
		0x040449,
		0x000764,
		0x0C2C8A,
		0x1852B1,
		0x397DD1,
		0x86B5E5,
		0xD3ECF8,
		0xF1E9BF,
		0xF8C95F,
		0xFFAA00,
		0xCC8000,
		0x995700,
		0x6A3403
	};

	m->color.palette = color_palette;
}

void	color_set3(t_mlx *m)
{
	const int color_palette[16] = {
		0x8B008B,
		0x9400D3,
		0x9932CC,
		0xBA55D3,
		0x800080,
		0xD8BFD8,
		0xDDA0DD,
		0xEE82EE,
		0xFF00FF,
		0xDA70D6,
		0xC71585,
		0xDB7093,
		0xFF1493,
		0xFF69B4,
		0xFFB6C1,
		0xFFC0CB
	};

	m->color.palette = color_palette;
}

void	color_set4(t_mlx *m)
{
	const int color_palette[16] = {
		0xFF0000,
		0xFF6600,
		0xFFCC00,
		0xCCFF00,
		0x99ff00,
		0x33ff00,
		0x00ff33,
		0x00FF99,
		0x00FFFF,
		0x0099FF,
		0x0033FF,
		0x0000FF,
		0x6600FF,
		0xCC00FF,
		0xFF00CC,
		0xFF0066
	};

	m->color.palette = color_palette;
}

void	switch_colorset(t_mlx *m)
{
	m->color.index = (m->color.index) + 1;
	if (m->color.index == 4)
		m->color.index = 0;
	if (m->color.index == 0)
		color_set1(m);
	else if (m->color.index == 1)
		color_set2(m);
	else if (m->color.index == 2)
		color_set3(m);
	else if (m->color.index == 3)
		color_set4(m);
}
