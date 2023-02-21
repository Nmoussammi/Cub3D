/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:09:42 by ibenmain          #+#    #+#             */
/*   Updated: 2023/02/19 01:42:50 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/cub3d.h"

void	ft_get_direction_player(t_data *data)
{
	if (data->dir.n)
		data->player.rotationangl = 3 * M_PI_2;
	else if (data->dir.s)
		data->player.rotationangl = M_PI_2;
	else if (data->dir.e)
		data->player.rotationangl = 0;
	else if (data->dir.w)
		data->player.rotationangl = M_PI;
}

void	ft_init_player(t_data *data)
{
	ft_get_direction_player(data);
	data->player.movespeed = 1.5;
	data->player.walkdirection = 0;
	data->player.sidedirection = 0;
	data->player.turndirection = 0;
	data->player.rotationspeed = 0.03;
	data->player.fov_angle = 60 * (M_PI / 180);
	data->player.num_ray = WIDTH_WIN;
	data->player.pos_x = -1;
	data->player.pos_y = -1;
	data->player.wall_hit_x = 0;
	data->player.wall_hit_y = 0;
	data->mouse = WIDTH_WIN / 2;
}

void	execution(t_data *data)
{
	ft_init_player(data);
	ft_position_player(data);
	data->rays = (t_rays *)malloc(sizeof(t_rays) * data->player.num_ray);
	if (!data->rays)
		ft_print_error("error: allocation failed");
	ft_mlx_wind(data);
	ft_mlx_loop(data);
}

int	ft_cub3d(int ac, char **av, t_data *data)
{
	if (parssing(ac, av, data) == 1)
		return (1);
	execution(data);
	return (0);
}
