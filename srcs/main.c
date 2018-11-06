/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szheng <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/22 16:26:24 by szheng            #+#    #+#             */
/*   Updated: 2018/11/06 14:47:01 by szheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fractol.h"

void	ft_check_input(t_mlx *m, int ac, char *av)
{
	if (ac != 2)
		ft_print_usage();
	if (!ft_strcmp(av, "1"))
		m->mode_num = 0;
	else if (!ft_strcmp(av, "2"))
		m->mode_num = 1;
	else if (!ft_strcmp(av, "3"))
		m->mode_num = 2;
	else if (!ft_strcmp(av, "4"))
		m->mode_num = 3;
	else
		ft_print_usage();
}

int		main(int ac, char **av)
{
	t_mlx	m;

	ft_check_input(&m, ac, av[1]);
	m.mlx = mlx_init();
	m.win = mlx_new_window(m.mlx, WIDTH, HEIGHT, "fractol");
	m.img.ptr = mlx_new_image(m.mlx, WIDTH, HEIGHT);
	setup(&m);
	draw(&m);
	print_instructions(&m);
	mlx_key_hook(m.win, deal_key, &m);
	mlx_mouse_hook(m.win, deal_mouse, &m);
	mlx_hook(m.win, 6, 0, julia_mouse_tracker, &m);
	mlx_loop(m.mlx);
	return (0);
}
