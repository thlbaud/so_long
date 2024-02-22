/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:54:22 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/22 14:07:34 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/mlx_linux/mlx.h"
#include "../HDRS/structure.h"
#include <stdlib.h>

void	_freemap(char **map)
{
	int	i;

	i = 0;
	while (map[i])
		free(map[i++]);
	free(map);
}

static void	_free_s_map(t_block ***s_map, int stop)
{
	int	temp;
	int	x1;
	int	x2;

	x1 = 0;
	while (s_map[x1])
	{
		x2 = 0;
		if (stop > 0)
		{
			while (s_map[x1][x2])
			{
				if (s_map[x1][x2]->nature == 'D' && s_map[x1][x2]->bad)
					free (s_map[x1][x2]->bad);
				free (s_map[x1][x2]);
				x2 += 3;
			}
		}
		temp = -1;
		while (++temp < 3)
			free (s_map[x1 + temp]);
		x1 += 3;
	}
	free (s_map);
}

static void	_free_mlx(t_vars *vars, t_data *img, int stop)
{
	if (stop >= 4)
		mlx_destroy_image(vars->mlx, img->img);
	if (stop >= 3)
		mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free (vars->mlx);
}

static void	_free_texture_c(t_colors *colors)
{
	if (colors->explosion_3)
		free (colors->explosion_3);
	if (colors->explosion_4)
		free (colors->explosion_4);
}

static void	_free_texture_b(t_colors *colors)
{
	if (colors->player_shoot2_left)
		free (colors->player_shoot2_left); 
	if (colors->player_shoot3_left)
		free (colors->player_shoot3_left);
	if (colors->player_shoot4_left)
		free (colors->player_shoot4_left);
	if (colors->player_shoot5_left)
		free (colors->player_shoot5_left);
	if (colors->player_shoot1_right)
		free (colors->player_shoot1_right);
	if (colors->player_shoot2_right)
		free (colors->player_shoot2_right);
	if (colors->player_shoot3_right)
		free (colors->player_shoot3_right);
	if (colors->player_shoot4_right)
		free (colors->player_shoot4_right);
	if (colors->player_shoot5_right)
		free (colors->player_shoot5_right);
	if (colors->explosion_1)
		free (colors->explosion_1);
	if (colors->explosion_2)
		free (colors->explosion_2);
	_free_texture_c(colors);
}

static void	_free_texture_a(t_colors *colors)
{
	if (colors->player_left)
		free (colors->player_left);
	if (colors->player_right)
		free (colors->player_right);
	if (colors->opps_low)
		free (colors->opps_low);
	if (colors->opps_mid)
		free (colors->opps_mid);
	if (colors->opps_top)
		free (colors->opps_top);
	if (colors->collect)
		free (colors->collect);
	if (colors->door)
		free (colors->door);
	if (colors->empty)
		free (colors->empty);
	if (colors->wall)
		free (colors->wall);
	if (colors->proj)
		free (colors->proj);
	if (colors->player_shoot1_left)
		free (colors->player_shoot1_left);
	_free_texture_b(colors);
}

void	_free_all(t_struct *g, int stop)
{
	_freemap(g->info->c_map);
	if (stop >= 0)
		_free_s_map(g->info->s_map, stop);
	if (stop > 1)
		_free_mlx(g->vars, g->img, stop);
	if (stop > 4)
		_free_texture_a(g->info->colors);
	exit (EXIT_FAILURE);
}