/*
** EPITECH PROJECT, 2020
** my_second_round
** File description:
** return
*/

#include "../include/my.h"

sfVertex my_vertex(sfVector3f p)
{
    sfVertex vertex;
    unsigned char r = p.z * 16 + 20;
    unsigned char gb = p.z * 8 + 20;

    vertex.position = (sfVector2f) {p.x, p.y};
    vertex.color = (sfColor) {r, gb, gb, 255};

    if (p.z > 8) vertex.color = sfWhite;
    if (p.z == 0) vertex.color = (sfColor) {50, 25, 25, 255};
    return (vertex);
}

sfVertexArray *link_vertex(sfVertex tab[4], sfVector3f pos)
{
    sfVertexArray *vertex_array = sfVertexArray_create();

    for (int i = 0; i < 4; i++)
        if (pos.x < 0 || pos.x > 128 || pos.y < 0 || pos.y > 64)
            return (vertex_array);

    if (pos.z > 4.0 || pos.z == 0.0)
        sfVertexArray_append(vertex_array, tab[3]);
    for (int p = 0 ; p < 4 ; p++) {
        if (pos.z > 4.0 || pos.z == 0.0)
            sfVertexArray_append(vertex_array, tab[p]);
    }
    sfVertexArray_setPrimitiveType(vertex_array, sfQuads);
    return (vertex_array);
}

sfVertexArray *link_water(sfVertex tab[4], sfVector3f pos)
{
    sfVertexArray *va = sfVertexArray_create();

    for (int i = 0; i < 4; i++)
    if (pos.x < 0 || pos.x > 128 || pos.y < 0 || pos.y > 64)
        return (va);

    sfVertexArray_append(va, tab[3]);
    for (int i = 0; i < 4; i++)
        sfVertexArray_append(va, tab[i]);
    sfVertexArray_setPrimitiveType(va, sfQuads);
    return (va);
}

sfVertexArray *my_vertex_water(sfVector3f **water, sfRenderWindow *window)
{
    sfVertexArray *vertex_water;
    sfVertex tab[4];

    for (int i = 0 ; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            tab[0].position = (sfVector2f) {water[j][i + 1].x, water[j][i + 1].y };
            tab[0].color = (sfColor) {100, 100, 255, 127};
            tab[1].position = (sfVector2f) {water[j + 1][i + 1].x, water[j + 1][i + 1].y };
            tab[1].color = (sfColor) {100, 100, 255, 127};
            tab[2].position = (sfVector2f) {water[j + 1][i].x, water[j + 1][i].y };
            tab[2].color = (sfColor) {100, 100, 255, 127};
            tab[3].position = (sfVector2f) {water[j][i].x, water[j][i].y};
            tab[3].color = (sfColor) {100, 100, 255, 127};
            vertex_water = link_water(tab, water[j][i]);
            sfRenderWindow_drawVertexArray(window, vertex_water, NULL);
            sfVertexArray_destroy(vertex_water);
        }
    }
    return (vertex_water);
}

sfVertexArray *my_vertex_array(sfVector3f **pos, sfRenderWindow *window)
{
    sfVertexArray *vertex_array;
    sfVector2i mouse = sfMouse_getPositionRenderWindow(window);
    sfVector2u size = sfRenderWindow_getSize(window);

    mouse.x = mouse.x  * 128 / size.x;
    mouse.y = mouse.y * 64 / size.y;
    for (int i = 0 ; i < MAP_Y - 1; i++) {
        for (int j = 0; j < MAP_X - 1; j++) {
            make_mountain(&pos[i][j], mouse, window);
            sfVertex vertex1 = my_vertex(pos[i][j + 1]);
            sfVertex vertex2 = my_vertex(pos[i + 1][j + 1]);
            sfVertex vertex3 = my_vertex(pos[i + 1][j]);
            sfVertex vertex4 = my_vertex(pos[i][j]);
            sfVertex tab[4] = {vertex1, vertex2, vertex3, vertex4};
            vertex_array = link_vertex(tab, pos[i][j]);
            sfRenderWindow_drawVertexArray(window, vertex_array, NULL);
            sfVertexArray_destroy(vertex_array);
        }
    }
    return (vertex_array);
}