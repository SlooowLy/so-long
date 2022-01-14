#ifndef LIB_H
# define LIB_H

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
#define relative_kha_w "./images/khazix_w.xpm"
#define relative_kha_a "./images/khazix_a.xpm"
#define relative_kha_d "./images/khazix_d.xpm"
#define relative_kha_s "./images/khazix_s.xpm"
#define relative_kha_evolved "./images/khazix_eve.xpm"
#define relative_path "./images/wall.xpm"
#define relative_path5 "./images/openeddoor.xpm"
#define relative_path6 "./images/closeddoor.xpm"
#define relative_path_kha_a "./images/kha_eve_a.xpm"
#define relative_path_kha_d "./images/kha_eve_d.xpm"
#define relative_path_kha_s "./images/kha_eve_s.xpm"
#define relative_path_kha_w "./images/kha_eve_w.xpm"

typedef struct s_map
{
	int		*walls;
	int		wallsnumber;
	int		*door;
	int		doornumber;
	int		*coll;
	int		collnumber;
	int		player;
	int		collgot;
}				t_map;

typedef struct s_image
{
	void	*img1;
	void	*img2;
	void	*img_d;
	void	*img_evolved;
	void	*img4;
	void	*img5;
	void	*img6;
	void	*kha;
}				t_image;

typedef struct s_player
{
	int	px;
	int	py;	
}				t_player;

typedef struct s_imageinfo
{
	int	x;
	int	y;	
}				t_imageinfo;

typedef struct	s_data
{
	void		*img;
    int         i;
    int         j;
	int			*addr;
	int			dar;
	void		*mlx;
	char		*map_d;
	char		**map;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
	int			player_eve;
	int			numberofmovements;
    t_map		mapinfo;
	t_image		imgj;
	t_player	player;
	t_imageinfo	imageinfo;
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

#endif