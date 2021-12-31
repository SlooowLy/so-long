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

int	read_map(char **all, int fd);

#endif