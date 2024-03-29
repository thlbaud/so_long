/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structure.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmouche <tmouche@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/31 15:53:48 by tmouche           #+#    #+#             */
/*   Updated: 2024/03/06 18:31:22 by tmouche          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURE_H
# define STRUCTURE_H
# define SPR_S 60
# define BUFFER_SIZE 1000000
# define SSIZE_X 1920
# define SSIZE_Y 1020
# define FPS 60
# define SPEED_CHARA 25
# define SPEED_LASER 100
# define SPEED_ANIM 10
# define RANGE_LASER 10
# define U_SEC 999999
# include <stddef.h>

typedef struct s_opps
{
	int				x1;
	int				x2;
	int				dir;
	int				sens;
	int				state;
	struct s_opps	*prev;
	struct s_opps	*next;
}				t_opps;

typedef struct s_block
{
	char	type;
	t_opps	*bad;
}				t_block;

typedef struct s_data
{
	void			*img;
	char			*addr;
	int				bits_per_pixel;
	int				line_length;
	int				endian;
}					t_data;

typedef struct s_colors
{
	int			*p_r;
	int			*p_l;
	int			*opps_bot;
	int			*opps_top;
	int			*opps_mid;
	int			*empty;
	int			*wall;
	int			*collect;
	int			*door;
	int			*proj;
	int			*p_shoot2_l;
	int			*p_shoot1_l;
	int			*p_shoot3_l;
	int			*p_shoot4_l;
	int			*p_shoot5_l;
	int			*p_shoot1_r;
	int			*p_shoot2_r;
	int			*p_shoot3_r;
	int			*p_shoot4_r;
	int			*p_shoot5_r;
	int			*explosion_1;
	int			*explosion_2;
	int			*explosion_3;
	int			*explosion_4;
	int			*explosion_5;
	int			*explosion_6;
	int			*laser_1;
	int			*laser_2;
	int			*laser_3;
	int			*shield;
}				t_colors;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_offs
{
	int	u;
	int	d;
	int	l;
	int	r;
}				t_offs;

typedef struct s_proj
{
	int		o_x2;
	int		x1;
	int		x2;
	int		limit;
	int		shoot;
	t_block	*laser;
}				t_proj;

typedef struct s_invent
{
	t_block	*empty;
	t_block	*wall_in;
	t_block	*wall_out;
	t_block	*exit;
	t_block	*collect;
	t_block	*player;
	t_block	*shield;
}				t_invent;

typedef struct s_map
{
	int			freeze;
	int			unkillable;
	int			map_width;
	int			map_height;
	char		**c_map;
	int			p_x1;
	int			p_x2;
	int			collect;
	int			step;
	int			vec;
	int			player_state;
	int			mv_x;
	int			mv_y;
	t_block		***s_map;
	t_invent	*inv;
	t_opps		**bad;
	t_colors	*colors;
	t_proj		*proj;
}				t_map;

typedef struct s_path
{
	char	*empty;
	char	*door;
	char	*collec;
	char	*player;
	char	*wall;
	char	*opps;
	char	*proj;
}				t_path;

typedef struct s_struct
{
	t_map			*info;
	t_vars			*vars;
	t_data			*img;
}				t_struct;

int		_lstsize(t_opps *lst);
t_opps	*_lstlast(t_opps *lst);
void	_lstclear(t_opps **lst);
t_opps	*_lstnew(int x1, int x2);
int		_lstadd_back(t_opps **lst, t_opps *new);
void	_lstadd_front(t_opps **lst, t_opps *new);
void	_lst_del_struct(t_opps *lst);

void	_free_all(t_struct *glob, int stop);
void	_free_texture_a(t_colors *colors);
void	_freemap(char **map);

#endif
