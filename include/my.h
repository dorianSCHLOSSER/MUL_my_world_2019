/*
** EPITECH PROJECT, 2019
** _MY_H_
** File description:
** return
*/

#ifndef _MY_H_
#define _MY_H_
#include <SFML/Graphics.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/System.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <math.h>
#define M 3.14159265359
#define MAP_X 50
#define MAP_Y 50

void keyboardescape(sfRenderWindow *window);
int my_principal_win(void);
int draw_line(sfRenderWindow *window, sfVertexArray *);
sfVector3f **create_2d_map(int index, sfVector3f **pos);
float PerlinNoise_2D(float x, float y, double n, float pas3D);
sfVertexArray *my_vertex_array(sfVector3f **pos, sfRenderWindow *);
sfVertexArray *my_vertex_water(sfVector3f **water, sfRenderWindow *);
sfVector3f project_iso_point(int x, int y, float z);
void draw_buttons(sfRenderWindow *window);
void make_mountain(sfVector3f *pos, sfVector2i vec, sfRenderWindow *window);

#endif
