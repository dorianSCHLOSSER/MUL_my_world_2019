/*
** EPITECH PROJECT, 2020
** pressed
** File description:
** return
*/

#include "../include/my.h"

void keyboardescape(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            sfRenderWindow_close(window);
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

