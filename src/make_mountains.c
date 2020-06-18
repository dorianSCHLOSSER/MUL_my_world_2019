/*
** EPITECH PROJECT, 2020
** make_mountains
** File description:
** to make mountains
*/

#include "../include/my.h"

int ok(sfVector2i vec, sfVector3f *pos, float x, float y)
{
    sfVector2i p = {(int) pos->x, (int) pos->y};
    vec.x += x;
    vec.y += y;

    if (vec.x <= p.x + 1 && vec.x >= p.x - 1 &&
        vec.y <= p.y + 1 && vec.y >= p.y - 1)
        return (1);
    return (0);
}

void move_map(sfRenderWindow *window, sfVector2i vec, int click)
{
    static int startx = 0;
    static int starty = 0;
    static int ok = 1;
    const sfView *view1 = sfRenderWindow_getView(window);
    sfView *view = sfView_copy(view1);
    sfVector2f center = sfView_getCenter(view);
    if (click == 1 && ok == 1) {
        ok = 0;
        startx = center.x + vec.x;
        starty = center.y + vec.y;
    }
    if (click == 0) 
        ok = 1;
    if (click == 1) {
        center.x = (float) (startx - vec.x);
        center.y = (float) (starty - vec.y);
    }
    sfView_setCenter(view, center);
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
}

void make_mountain(sfVector3f *pos, sfVector2i vec, sfRenderWindow *window)
{
    static int mode = 1;
    const sfView *view = sfRenderWindow_getView(window);
    sfVector2f center = sfView_getCenter(view);
    float x = (int) (center.x - 64);
    float y = (int) (center.y - 32);
    int click = sfMouse_isButtonPressed(0);

    if (click && vec.x >= 2 && vec.x <= 6 && vec.y <= 12 && vec.y >= 7)
        mode = 1;
    if (click && vec.x >= 2 && vec.x <= 6 && vec.y <= 17 && vec.y >= 12)
        mode = -1;
    if (click && vec.x >= 2 && vec.x <= 6 && vec.y <= 24 && vec.y >= 20)
        mode = 0;
    if (click && ok(vec, pos, x, y) == 1) {
        if ((mode == 1 && pos->z < 30) || (mode == -1 && pos->z > 2))
            pos->z += mode;
        pos->y -= (float) mode / 2;
    }
    if (mode == 0) move_map(window, vec, click);
}