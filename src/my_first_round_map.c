/*
** EPITECH PROJECT, 2020
** first_round_map
** File description:
** return
*/

#include "../include/my.h"

sfVector3f **create_map(int index, sfVector3f **pos)
{
    static float move = 0;

    for (int i = 0 ; i < MAP_Y - 1; i++) {
        for (int j = 0 ; j < MAP_X -1 ; j++) {
            if (index == 1) {
                pos[i][j].z = PerlinNoise_2D(i, j, 8, 1000) * 10;
                pos[i][j].z = (pos[i][j].z < 4) ? 4 : pos[i][j].z;
            }
            if (index == 2 && move != 1) {
                pos[i][j].z = PerlinNoise_2D(i, j, 7 + move, 1000) * 6;
                pos[i][j].z = (pos[i][j].z < 4) ? 4 : pos[i][j].z;
            }
        }
    }
    move += 0.3;
    if (move >= 10) move = 0.05;
    return (pos);
}

sfVector3f **my_malloc_vector(sfVector3f **pos)
{
    static int nb = 0;

    if (nb < 2) {
        pos = malloc(sizeof(sfVector3f *) * MAP_Y);
        for (int i = 0 ; i < MAP_Y; i++)
            pos[i] = malloc(sizeof(sfVector3f) * MAP_X);
        nb++;
    }
    return (pos);
}

sfVector3f project_iso_point(int x, int y, float z)
{
    sfVector3f pos2;

    pos2.x = cos(45/M/180) * x - cos(45/M/180) * y + 60;
    pos2.y = sin(35/M/180) * 8 * y + sin(35/M/180) * x - z + 20;
    pos2.z = z;
    return (pos2);
}

sfVector3f **create_2d_map(int index, sfVector3f **pos)
{
    pos = my_malloc_vector(pos);
    create_map(index, pos);

    for (int i = 0 ; i < MAP_Y; i++)
        for (int j = 0 ; j < MAP_X; j++)
            pos[i][j] = project_iso_point(j, i, pos[i][j].z);
    return (pos);
}