/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_looper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:23:10 by tmouche           #+#    #+#             */
/*   Updated: 2024/02/29 15:59:35 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minilibx-linux/mlx.h"
#include "../HDRS/structure.h"
#include "../HDRS/movement.h"
#include "../HDRS/texture.h"
#include "../HDRS/window.h"
#include <sys/time.h>
#include <stdlib.h>

/*static inline void	_refresh_anim(t_struct *g, int *multi)
{
	
}*/

/*static inline void	_character(t_struct *g, int *multi)
{
	if (g->info->mv_x != 0 || g->info->mv_y != 0)
		_player(g, g->info, g->info->mv_x);
	_ennemies(g, g->info, *(g->info->bad));
	++multi[0];
	if (multi[0] == SPEED_CHARA)
		multi[0] = 0;
}*/

/*static inline void	_projectile(t_struct *g, t_proj* proj,
								t_block ***s_map, int *multi)
{
	if (g->info->s_map[proj->x1][proj->x2])
}*/

static inline void	_framer(t_struct *g, int *multi)
{
	_texture_to_img(g, g->info, g->info->s_map);
	mlx_clear_window(g->vars->mlx, g->vars->win);
	mlx_put_image_to_window(g->vars->mlx, g->vars->win, g->img->img, 0, 0);
	if (_disp_info(g, g->info->collect, g->info->step) == -1)
		_free_all(g, 5);
	++multi[0];
	if (multi[0] == FPS)
		multi[0] = 0;
}

int	_exchanger(t_struct *g)
{
	struct timeval	clock;
	static int		m_fps = 0;	
	//static int		m_proj = 0;
	//static int		m_chara = 0;
	//static int		m_anim = 0;

	gettimeofday(&clock, NULL);
	if (clock.tv_usec >= U_SEC / FPS * m_fps
		&& clock.tv_usec <= U_SEC / FPS * (m_fps + 1))
		_framer(g, &m_fps);
	/*if (clock.tv_usec >= U_SEC / SPEED_PROJ * m_proj
		&& clock.tv_usec <= U_SEC / SPEED_PROJ * (m_proj + 1)
		&& g->info->proj->limit > 0)
		_projectile(g, &m_proj);*/
	/*if (clock.tv_usec >= U_SEC / SPEED_CHARA * m_chara
		&& clock.tv_usec <= U_SEC / SPEED_CHARA * (m_chara + 1))
		_character(g, &m_chara);*/
	/*if (clock.tv_usec >= U_SEC / SPEED_ANIM * m_anim
		&& clock.tv_usec <= U_SEC / SPEED_ANIM * (m_anim + 1))
		_refresh_anim(g, &m_anim);*/
	return (0);	
}