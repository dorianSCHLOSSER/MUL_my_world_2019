/*
** EPITECH PROJECT, 2020
** draw_buttons
** File description:
** to draw the buttons
*/

#include "../include/my.h"

void draw_last_button(sfRenderWindow *window, float x, float y)
{
    sfCircleShape *button = sfCircleShape_create();

    sfCircleShape_setOutlineThickness(button, 0.5);
    sfCircleShape_setOutlineColor(button, sfBlack);
    sfCircleShape_setPosition(button, (sfVector2f) {x + 2, y + 20});
    sfCircleShape_setRadius(button, 2);
    sfRenderWindow_drawCircleShape(window, button, NULL);
    sfCircleShape_destroy(button);
}

sfVertexArray *create_vertexArray(sfVertex tab[6])
{
    sfVertexArray *va = sfVertexArray_create();

    sfVertexArray_append(va, tab[2]);
    sfVertexArray_append(va, tab[3]);
    sfVertexArray_append(va, tab[0]);
    sfVertexArray_append(va, tab[1]);
    sfVertexArray_append(va, tab[2]);
    sfVertexArray_append(va, tab[4]);
    sfVertexArray_append(va, tab[5]);
    sfVertexArray_append(va, tab[1]);
    sfVertexArray_setPrimitiveType(va, sfQuads);
}

void draw_buttons(sfRenderWindow *window)
{
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f center = sfView_getCenter(view);
    float x = center.x - 64;
    float y = center.y - 32;

    sfVertex v1 = {(sfVector2f) {x + 3, y + 7}, sfGreen, (sfVector2f) {1, 1}};
    sfVertex v2 = {(sfVector2f) {x + 2, y + 12}, sfWhite, (sfVector2f) {1, 1}};
    sfVertex v3 = {(sfVector2f) {x + 6, y + 12}, sfWhite, (sfVector2f) {1, 1}};
    sfVertex v4 = {(sfVector2f) {x + 5, y + 7}, sfGreen, (sfVector2f) {1, 1}};
    sfVertex v5 = {(sfVector2f) {x + 5, y + 17}, sfRed, (sfVector2f) {1, 1}};
    sfVertex v6 = {(sfVector2f) {x + 3, y + 17}, sfRed, (sfVector2f) {1, 1}};
    sfVertex tab[6] = {v1, v2, v3, v4, v5, v6};
    sfVertexArray *va = create_vertexArray(tab);

    sfRenderWindow_drawVertexArray(window, va, NULL);
    sfVertexArray_destroy(va);
    draw_last_button(window, x, y);
}