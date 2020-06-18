/*
** EPITECH PROJECT, 2020
** principal
** File description:
** return
*/

#include "../include/my.h"

void destroy_all(sfRenderWindow *window, sfVector3f **pos, sfVector3f **water)
{
    sfRenderWindow_destroy(window);
    for (int i = 0; i < MAP_X; i++) free(pos[i]);
    free(pos);
    for (int i = 0; i < MAP_X; i++) free(water[i]);
    free(water);
}

sfRenderWindow *open_window(void)
{
    sfRenderWindow *window;
    sfVideoMode video_mode = {128, 64, 32};
    sfView *view = sfView_create();

    sfView_reset(view, (sfFloatRect) {0, 0, 128, 64});
    window = sfRenderWindow_create(video_mode, "My_Wold", \
    sfResize | sfClose, NULL);
    sfRenderWindow_setFramerateLimit(window, 60);
    sfRenderWindow_setView(window, view);
    sfView_destroy(view);
    return (window);
}

int my_principal_win(void)
{
    sfRenderWindow *window = open_window();
    sfVector3f **pos;
    sfVector3f **water;

    pos = create_2d_map(1, pos);
    while (sfRenderWindow_isOpen(window)) {
        keyboardescape(window);
        sfRenderWindow_clear(window, (sfColor) {100, 50, 150, 255});
        water = create_2d_map(2, water);
        my_vertex_water(water, window);
        my_vertex_array(pos, window);
        draw_buttons(window);
        sfRenderWindow_display(window);
    }
    destroy_all(window, pos, water);
    return (0);
}