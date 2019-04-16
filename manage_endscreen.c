/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** manage endscreen.c
*/

#include "runner.h"

void display_endscreen(basis_t *basis)
{
    for (int i = 0; i <= 4; i++) {
        sfRenderWindow_drawSprite(basis->window,
            basis->backgrounds->background1[i]->sprite, NULL);
        sfRenderWindow_drawSprite(basis->window,
            basis->backgrounds->background2[i]->sprite, NULL);
    }
    sfRenderWindow_drawSprite(basis->window,
        basis->end_screen->buttons[0]->sprite, NULL);
    sfRenderWindow_drawSprite(basis->window,
        basis->end_screen->buttons[1]->sprite, NULL);
    sfRenderWindow_drawText(basis->window, basis->end_screen->texts[0], NULL);
    sfRenderWindow_drawText(basis->window, basis->end_screen->texts[1], NULL);
    sfRenderWindow_drawText(basis->window, basis->end_screen->texts[2], NULL);
    sfRenderWindow_drawText(basis->window, basis->score->text_t, NULL);
    sfRenderWindow_drawText(basis->window, basis->score->text_n, NULL);
    sfRenderWindow_drawSprite(basis->window, basis->end_screen->arrow->sprite,
        NULL);
}

void move_arrow_down_end_screen(basis_t *basis)
{
    sfVector2f pos = sfSprite_getPosition(basis->end_screen->arrow->sprite);
    sfVector2f new = create_vector(((WINDOW_WIDTH - (101 * 5))/2) - 140,
        pos.y + 140);

    basis->end_screen->pos_of_arrow = 1;
    sfSprite_setPosition(basis->end_screen->arrow->sprite, new);
}

void move_arrow_up_end_screen(basis_t *basis)
{
    sfVector2f pos = sfSprite_getPosition(basis->end_screen->arrow->sprite);
    sfVector2f new = create_vector(((WINDOW_WIDTH - (101 * 7.5))/2) - 150, 390);

    basis->end_screen->pos_of_arrow = 0;
    sfSprite_setPosition(basis->end_screen->arrow->sprite, new);
}

void manage_action_end_screen(basis_t *basis, sfKeyEvent event)
{
    if (event.code == sfKeyReturn || event.code == sfKeyRight) {
        if (basis->end_screen->pos_of_arrow != 0) {
            sfRenderWindow_close(basis->window);
        }
        basis->gamestatus = MAIN_MENU;
        basis->swap_to_next_phase = 1;
    }
    if (event.code == sfKeyDown && basis->end_screen->pos_of_arrow == 0) {
        move_arrow_down_end_screen(basis);
    }
    if (event.code == sfKeyUp && basis->end_screen->pos_of_arrow == 1) {
        move_arrow_up_end_screen(basis);
    }
}

void end_screen_events(basis_t *basis, sfEvent *event)
{
    if (sfRenderWindow_pollEvent(basis->window, event) == sfTrue) {
        if (event->type == sfEvtKeyPressed)
            manage_action_end_screen(basis, event->key);
        if (event->type  == sfEvtClosed) {
            basis->swap_to_next_phase = 1;
            basis->gamestatus = MAIN_MENU;
            sfRenderWindow_close(basis->window);
        }
        return;
    }
}