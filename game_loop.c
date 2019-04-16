/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** game loop
*/

#include "runner.h"

void manage_action_ingame(basis_t *basis, sfKeyEvent event)
{
    if (basis->player->jump == sfTrue || basis->player->slide == sfTrue)
        return;
    if (event.code == sfKeySpace) {
        sfClock_restart(basis->player->movement_clock);
        move_rect_to(&basis->player->player->rect,
            create_vector(PLAYER_JUMP_X, PLAYER_JUMP_Y),
            create_vector(PLAYER_JUMP_OFFSET, 350));
        basis->player->jump = sfTrue;
        basis->player->sprite_nbr = 0;
    } else if (event.code == sfKeyS) {
        sfClock_restart(basis->player->movement_clock);
        move_rect_to(&basis->player->player->rect,
            create_vector(PLAYER_SLIDE_X, PLAYER_SLIDE_Y),
            create_vector(PLAYER_SLIDE_OFFSET, 350));
        basis->player->slide = sfTrue;
        basis->player->sprite_nbr = 0;
    }
}

void analize_events_ingame(basis_t *basis, sfEvent *event)
{
    if (sfRenderWindow_pollEvent(basis->window, event) == sfTrue) {
        if (event->type == sfEvtKeyPressed)
            manage_action_ingame(basis, event->key);
        if (event->type  == sfEvtClosed) {
            basis->swap_to_next_phase = 1;
            basis->gamestatus = END_SCREEN_LOSE;
            sfRenderWindow_close(basis->window);
        }
        return;
    }
}

void check_for_win(basis_t *basis)
{
    obstacle_t *tmp = basis->assets->map->obstacles;

    while (tmp->next != NULL)
        tmp = tmp->next;
    if (check_obstacle_left_of_screen(tmp->obstacle) == 1) {
        basis->gamestatus = END_SCREEN_WIN;
        basis->swap_to_next_phase = 1;
    }
}

void draw_game(basis_t *basis)
{
    for (int i = 0; i <= 4; i++) {
        sfRenderWindow_drawSprite(basis->window,
            basis->backgrounds->background1[i]->sprite, NULL);
        sfRenderWindow_drawSprite(basis->window,
            basis->backgrounds->background2[i]->sprite, NULL);
    }
    for (obstacle_t *tmp = basis->assets->map->obstacles; tmp != NULL;
        tmp = tmp->next)
        sfRenderWindow_drawSprite(basis->window, tmp->obstacle->sprite, NULL);
    sfRenderWindow_drawSprite(basis->window, basis->arrow_sign->sprite, NULL);
    sfRenderWindow_drawSprite(basis->window, basis->player->player->sprite,
        NULL);
    sfRenderWindow_drawText(basis->window, basis->score->text_t, NULL);
    sfRenderWindow_drawText(basis->window, basis->score->text_n, NULL);
}

void manage_game(basis_t *basis, sfEvent *event)
{
    sfTime time = sfClock_getElapsedTime(basis->assets->movement_time);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.01) {
        background_movement(basis->backgrounds);
        manage_obstacles(basis->assets->map);
        basis->arrow_sign->movement(basis->arrow_sign);
        move_player(basis->player);
        manage_collision(basis);
        modify_score(basis->score);
        sfClock_restart(basis->assets->movement_time);
        check_for_win(basis);
    }
    draw_game(basis);
    analize_events_ingame(basis, event);
}