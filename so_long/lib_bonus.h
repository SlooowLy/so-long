#ifndef LIB_BONUS_H
# define LIB_BONUS_H

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <mlx.h>
#include <fcntl.h>

#define d 2
#define s 1
#define a 0
#define w 13
#define relative_path2 "./images/theopen.xpm"
#define relative_path4 "./images/yummiw.xpm"
#define khaw "./images/khazix_w.xpm"
#define khaa "./images/khazix_a.xpm"
#define khad "./images/khazix_d.xpm"
#define khas "./images/khazix_s.xpm"
#define relative_path "./images/wall.xpm"
#define r5 "./images/openeddoor.xpm"
#define r6 "./images/closeddoor.xpm"
#define ekhaa "./images/kha_eve_a.xpm"
#define ekhad "./images/kha_eve_d.xpm"
#define ekhas "./images/kha_eve_s.xpm"
#define ekhaw "./images/kha_eve_w.xpm"
#define musa "./images/rammus_a.xpm"
#define musd "./images/rammus_d.xpm"

typedef struct s_map
{
	int		collnumber;
	int		collgot;
}				t_map;

typedef struct s_image
{
	void	*i1;
	void	*i2;
	void	*id;
	void	*img_evolved;
	void	*i4;
	void	*i5;
	void	*i6;
	void	*kha;
	void	*rm;
}				t_image;

typedef struct s_25line
{
	int	k;
	int	j;
	int	i;
	int	x;
	int	y;
}				t_25line;

typedef struct	s_data
{
	void		*img;
    int         i;
    int         j;
	int			x;
	int			y;
	void		*ml;
	char		*map_d;
	char		**map;
	void		*wi;
	int			wt;
	int			hg;
	int			line_length;
	int			endian;
	int			player_eve;
	int		numberofmovements;
	int			message;
    t_map		mapinfo;
	t_image		im;
	t_25line	n;
}				t_data;

int	    read_map(char **all, int fd);
int 	key_hook(int key, t_data *data);
void    give_null_value(t_data *data);
void    allocating(t_data *data);
char	**ft_split(char const *x, char c);
int 	check_map(char **map_c, char *map);
int		len(char *str);
void	ft_printf_d(long n, int fd);
void	destroy_all(t_data *data);
int 	ft_exit(t_data *data);
int		check_len(char **str);
int		collnumberr(t_data *data);
void	map_error(t_data *data);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
void	arg_error(t_data *data);
void	ft_free(char **str);
int		ft_itoa(int j, t_data *m);
void	change_player(t_data *m);
void	do_movements(t_data *m, int j, int k);
void	print_map1(t_data *m);
void	creat_images_window(t_data *m);
void	render_next_frame_2(t_data *m);
void	player_animation(int key, t_data *m);
void	give_value(t_data *data);
void	change_player_next_position(t_data *data, int j, int k, int r);
int		get_r(void);
int		check_enemy(t_data *data, int i);
int	check_safety1(t_data *data, int i);
int	check_safety(t_data *data, int i);
char	f_u_25line(t_data *m, int r, int j, int k);

#endif