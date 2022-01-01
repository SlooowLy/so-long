#ifndef LIB_H
# define LIB_H

#include<stdio.h>
#include<stdarg.h>
#include<unistd.h>
#include<stdlib.h>
#include <mlx.h>
#include <fcntl.h>

#define d 2
#define s 1
#define a 0
#define w 13
#define relative_path2 "./theopen.xpm"
#define relative_path4 "./yummiw.xpm"
#define relative_path3 "./khazixw.xpm"
#define relative_path "./wall.xpm"
#define relative_path5 "./openeddoor.xpm"
#define relative_path6 "./closeddoor.xpm"

typedef struct s_map
{
	char	*walls;
	int		wallsnumber;
	char	*door;
	int		doornumber;
	char	*coll;
	int		collnumber;
	int		player;
	int		collgot;
}				t_map;

typedef struct s_image
{
	void	*img1;
	void	*img2;
	void	*img3;
	void	*img4;
	void	*img5;
	void	*img6;
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
	void		*mlx;
	char		*map;
	void		*mlx_win;
	int			img_width;
	int			img_height;
	int			bits_per_pixel;
	int			line_length;
	int			endian;
    t_map		mapinfo;
	t_image		imgj;
	t_player	player;
	t_imageinfo	imageinfo;
}				t_data;

int	    read_map(char **all, int fd);
int 	key_hook(int key, t_data *data);
void    give_null_value(t_data *data);
void    allocating(t_data *data);


#endif