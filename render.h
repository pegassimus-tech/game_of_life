#ifndef RENDER_H
#define RENDER_H

#include <ncurses.h>

void init_render();
void close_render();
void draw_matrix(int** matrix, int a, int b, int speed);


#endif
