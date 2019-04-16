/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** manage main menu
*/

#include "runner.h"

void move_arrow_down(basis_t *basis)
{
    sfVector2f pos = sfSprite_getPosition(basis->main_menu->arrow->sprite);
    sfVector2f new = create_vector(((WINDOW_WIDTH - (101 * 5))/2) - 140,
        pos.y + 140);

    basis->main_menu->pos_of_arrow++;
    sfSprite_setPosition(basis->main_menu->arrow->sprite, new);
}

void move_arrow_up(basis_t *basis)
{
    sfVector2f pos = sfSprite_getPosition(basis->main_menu->arrow->sprite);
    sfVector2f new = create_vector(((WINDOW_WIDTH - (101 * 5))/2) - 140,
        pos.y - 140);

    basis->main_menu->pos_of_arrow--;
    sfSprite_setPosition(basis->main_menu->arrow->sprite, new);
}

void manage_action_main_menu(basis_t *basis, sfKeyEvent event)
{
    if (event.code == sfKeyReturn || event.code == sfKeyRight) {
        if (basis->main_menu->pos_of_arrow == 3)
            sfRenderWindow_close(basis->window);
        basis->gamestatus = RUNNING;
        basis->swap_to_next_phase = 1;
    }
    if (event.code == sfKeyDown && basis->main_menu->pos_of_arrow < 3)
        move_arrow_down(basis);
    if (event.code == sfKeyUp && basis->main_menu->pos_of_arrow > 0)
        move_arrow_up(basis);
}

void analize_events_main_menu(basis_t *basis, sfEvent *event)
{
    if (sfRenderWindow_pollEvent(basis->window, event) == sfTrue) {
        if (event->type == sfEvtKeyPressed)
            manage_action_main_menu(basis, event->key);
        if (event->type  == sfEvtClosed) {
            basis->swap_to_next_phase = 1;
            basis->gamestatus = RUNNING;
            sfRenderWindow_close(basis->window);
        }
        return;
    }
}

void manage_main_menu_screen(basis_t *basis, sfEvent *event)
{
    for (int i = 0; i <= 4; i++) {
        sfRenderWindow_drawSprite(basis->window,
        basis->backgrounds->background1[i]->sprite, NULL);
        sfRenderWindow_drawSprite(basis->window,
        basis->backgrounds->background2[i]->sprite, NULL);
        sfRenderWindow_drawSprite(basis->window,
            basis->main_menu->buttons[i]->sprite, NULL);
        sfRenderWindow_drawText(basis->window, basis->main_menu->texts[i],
            NULL);
    }
    player_idle(basis->player);
    sfRenderWindow_drawSprite(basis->window, basis->arrow_sign->sprite, NULL);
    sfRenderWindow_drawSprite(basis->window, basis->main_menu->arrow->sprite,
        NULL);
    sfRenderWindow_drawSprite(basis->window, basis->player->player->sprite,
        NULL);
    analize_events_main_menu(basis, event);
}