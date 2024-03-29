/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:54:49 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 15:22:05 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVEMENT_H
# define MOVEMENT_H
# include "structure.h"

void	_check_v(int x1, int x2, int o_x1, int (*check)[2]);
void	_check_h(int x1, int x2, int o_x2, int (*check)[2]);
void	_check_d(int x1, int x2, int *mv, int (*check)[2]);

void	_knife(t_map *info, t_block ***s_map, int keycode);

void	_this_is_the_end(t_struct *g, char c);
void	_collectible(t_map *info, int x1, int x2);

void	_move_opps(t_map *info, t_block ***s_map, t_opps *bad);
void	_move_player(t_struct *g, t_map *info, int d_x1, int d_x2);

void	_reset_chara(t_map *info, t_block ***s_map, int x1, int x2);
void	_replace_chara(t_block ***s_map, t_block *block, int x1, int x2);

void	_ennemies(t_struct *g, t_map *info, t_opps *bad);
void	_player(t_struct *g, t_map *info);

void	_define_projectile(t_map *info, t_proj *proj, int keycode);
void	_erase_proj(t_map *info, t_proj *laser, t_block ***s_map);
void	_laser(t_map *info, t_proj *laser);

#endif
