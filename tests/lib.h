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
#define relative_path2 "./images/theopen.xpm"
#define relative_path4 "./images/yummiw.xpm"
#define relative_path3 "./images/khazixw.xpm"
#define relative_path "./images/wall.xpm"
#define relative_path5 "./images/openeddoor.xpm"
#define relative_path6 "./images/closeddoor.xpm"

int	read_map(char **all, int fd);

#endif