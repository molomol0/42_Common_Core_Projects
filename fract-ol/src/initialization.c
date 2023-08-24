/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jdenis <jdenis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/28 13:49:55 by jdenis            #+#    #+#             */
/*   Updated: 2023/06/29 01:47:02 by jdenis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	clean_init(t_fractol *f)
{
	f->mlx = NULL;
	f->win = NULL;
	f->img = NULL;
	f->buf = NULL;
	f->set = -1;
	f->min_reel = 0;
	f->max_reel = 0;
	f->min_imaginaire = 0;
	f->max_imaginaire = 0;
	f->reel_value = 0;
	f->imaginaire_value = 0;
	f->mandelbox_s = 0;
	f->mandelbox_r = 0;
	f->mandelbox_f = 0;
	f->palette = NULL;
	f->color_pattern = -1;
	f->color = 0;
}

void	get_complex_space(t_fractol *f)
{
	if (f->set == MANDELBOX)
	{
		f->min_reel = -4.0;
		f->max_reel = 4.0;
		f->min_imaginaire = -4.0;
		f->max_imaginaire = f->min_imaginaire + (f->max_reel - f->min_reel)
			* HEIGHT / WIDTH;
	}
	else if (f->set == JULIA)
	{
		f->min_reel = -2.0;
		f->max_reel = 2.0;
		f->min_imaginaire = -2.0;
		f->max_imaginaire = f->min_imaginaire + (f->max_reel - f->min_reel)
			* HEIGHT / WIDTH;
	}
	else
	{
		f->min_reel = -2.0;
		f->max_reel = 1.0;
		f->max_imaginaire = -1.5;
		f->min_imaginaire = f->max_imaginaire + (f->max_reel - f->min_reel)
			* HEIGHT / WIDTH;
	}
}

static void	init_img(t_fractol *f)
{
	int		pixel_bits;
	int		line_bytes;
	int		endian;
	char	*buf;

	f->palette = ft_calloc((MAX_ITERATIONS + 1), sizeof(int));
	if (!(f->palette))
		clean_exit(msg("error initializing color scheme.", "", 1), f);
	f->img = mlx_new_image(f->mlx, WIDTH, HEIGHT);
	if (!(f->img))
		clean_exit(msg("image creation error.", "", 1), f);
	buf = mlx_get_data_addr(f->img, &pixel_bits, &line_bytes, &endian);
	f->buf = buf;
}

void	reinit_img(t_fractol *f)
{
	if (f->mlx && f->img)
		mlx_destroy_image(f->mlx, f->img);
	if (f->palette)
		free(f->palette);
	if (f->buf)
		f->buf = NULL;
	init_img(f);
}

void	init(t_fractol *f)
{
	f->mlx = mlx_init();
	if (!f->mlx)
		clean_exit(msg("MLX: error connecting to mlx.", "", 1), f);
	f->win = mlx_new_window(f->mlx, WIDTH, HEIGHT, "Fractol");
	if (!f->win)
		clean_exit(msg("MLX: error creating window.", "", 1), f);
	f->mandelbox_s = 2.0;
	f->mandelbox_r = 0.5;
	f->mandelbox_f = 1.0;
	get_complex_space(f);
	color_shift(f);
}
