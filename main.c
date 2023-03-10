/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ibenmain <ibenmain@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:53:04 by nmoussam          #+#    #+#             */
/*   Updated: 2023/02/19 01:56:39 by ibenmain         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parssing/cub3d.h"

int	ft_check_name_map(char *map_name)
{
	int	len;

	len = ft_strlen(map_name);
	if (map_name[len - 4] == '.' && map_name[len - 3] == 'c' && \
		map_name[len - 2] == 'u' && map_name[len - 1] == 'b')
		return (0);
	return (1);
}

void	ft_map_size(char *map, t_data *data)
{
	int		fd;
	char	*line;

	data->line_map = 0;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		ft_print_error("can't open file\n");
	line = get_next_line(fd);
	while (line != NULL)
	{
		data->line_map += 1;
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	free(line);
}

int	ft_check_error_tab(char **tab)
{
	int	nb;

	nb = 0;
	while (tab[nb] != NULL)
		nb++;
	return (nb);
}

void	ft_divide_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i])
	{
		if (ft_check_spase_in_line(data->map[i]))
			ft_print_error("error: invalid map");
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	*data;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		return (1);
	if (ft_cub3d(ac, av, data) == 1)
		return (1);
	ft_free_all_data(data);
	return (0);
}
