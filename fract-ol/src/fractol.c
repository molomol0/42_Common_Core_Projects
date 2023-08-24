/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:50:57 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/29 01:12:59 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	type_cmp(char *av, char *str, char c, char n)
{
	int	i;

	i = 0;
	while (av[i])
	{
		av[i] = ft_tolower(av[i]);
		i++;
	}
	if (!ft_strncmp(av, str, ft_strlen(str) + 1))
		return (1);
	else if (av[1] == '\0' && (av[0] == c || av[0] == n))
		return (1);
	return (0);
}

static void	get_set(t_fractol *f, char **av)
{
	if (type_cmp(av[1], "mandelbrot", 'm', '1'))
		f->set = MANDELBROT;
	else if (type_cmp(av[1], "julia", 'j', '2'))
		f->set = JULIA;
	else if (type_cmp(av[1], "mandelbox", 'x', '3'))
		f->set = MANDELBOX;
	else
		help_msg(f);
}

static void	get_julia_starting_values(t_fractol *f, int ac, char **av)
{
	if (f->set != JULIA || ac == 2)
	{
		f->reel_value = -0.766667;
		f->imaginaire_value = -0.09;
		return ;
	}
	if (ac == 3)
		help_msg(f);
	if (!ft_strchr(av[2], '.'))
		help_msg(f);
	if (!ft_strchr(av[3], '.'))
		help_msg(f);
	f->reel_value = ft_atof(av[2]);
	f->imaginaire_value = ft_atof(av[3]);
	if (f->reel_value > 2.0 || f->reel_value < -2.0)
		help_msg(f);
	if (f->imaginaire_value >= 2.0 || f->imaginaire_value <= -2.0)
		help_msg(f);
}

static void	handle_args(t_fractol *f, int ac, char **av)
{
	get_set(f, av);
	if (f->set != JULIA && ac > 3)
		help_msg(f);
	else if (f->set == JULIA && ac > 5)
		help_msg(f);
	get_julia_starting_values(f, ac, av);
	get_color(f, ac, av);
}

int	main(int ac, char **av)
{
	t_fractol	f;

	if (ac < 2)
	{
		clean_init(&f);
		help_msg(&f);
	}
	clean_init(&f);
	handle_args(&f, ac, av);
	init(&f);
	render(&f);
	print_controls();
	mlx_hook(f.win, EVENT_CLOSE_BTN, 0, end_fractol, &f);
	mlx_key_hook(f.win, key_event, &f);
	mlx_mouse_hook(f.win, mouse_event, &f);
	mlx_loop(f.mlx);
}
