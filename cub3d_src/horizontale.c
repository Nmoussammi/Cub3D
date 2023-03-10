/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizontale.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:22:28 by ibenmain          #+#    #+#             */
/*   Updated: 2023/02/19 01:58:24 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../parssing/cub3d.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int	handl_keyrelease(t_data *data)
{
	ft_free_all_data(data);
	exit(0);
}

void	ft_horizontal(double xstep, double ystep, t_data *data)
{
	double	y;

	y = 0;
	data->ray.next_hor_x = data->ray.xintercept_hor;
	data->ray.next_hor_y = data->ray.yintercept_hor;
	if (data->player.is_rayfacing_up)
		y = 1;
	while (data->ray.next_hor_x >= 0 && data->ray.next_hor_x < \
		data->line_max * TILE_SIZE && data->ray.next_hor_y >= 0 \
		&& data->ray.next_hor_y < data->len * TILE_SIZE)
	{
		if (_is_wall(data->ray.next_hor_y - y, data->ray.next_hor_x, data))
		{
			data->ray.found_wall_h = 1;
			data->ray.wall_hit_hor_x = data->ray.next_hor_x;
			data->ray.wall_hit_hor_y = data->ray.next_hor_y;
			break ;
		}
		data->ray.next_hor_x += xstep;
		data->ray.next_hor_y += ystep;
	}
}

void	ft_ray_cast_hor(t_data *data, double ray_angle)
{
	double	xstep;
	double	ystep;

	data->ray.yintercept_hor = floor(data->player.pos_y / TILE_SIZE) \
		* TILE_SIZE;
	if (data->player.is_rayfacing_down)
		data->ray.yintercept_hor += TILE_SIZE;
	data->ray.xintercept_hor = data->player.pos_x + \
	((data->ray.yintercept_hor - data->player.pos_y) / tan(ray_angle));
	ystep = TILE_SIZE;
	if (data->player.is_rayfacing_up)
		ystep *= -1;
	xstep = TILE_SIZE / tan(ray_angle);
	if (data->player.is_rayfacing_left && xstep > 0)
		xstep *= -1;
	if (data->player.is_rayfacing_right && xstep < 0)
		xstep *= -1;
	ft_horizontal(xstep, ystep, data);
}
