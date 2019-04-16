/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** player_movement
*/

#include "runner.h"

void player_jump(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->animation_time);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.2) {
        move_rect(&player->player->rect, create_vector(PLAYER_JUMP_OFFSET, 0));
        sfClock_restart(player->animation_time);
        player->sprite_nbr++;
    }
    player->player->speed.y = 10 * player->movement_time - 10;
    if (player->sprite_nbr == 10) {
        player->sprite_nbr = 0;
        player->jump = sfFalse;
        player->player->speed.y = 0;
        player->player->pos = create_vector(300, 590);
        sfSprite_setPosition(player->player->sprite, player->player->pos);
        move_rect_to(&player->player->rect,
            create_vector(PLAYER_RUN_X, PLAYER_RUN_Y),
            create_vector(PLAYER_RUN_OFFSET, 350));
        sfClock_restart(player->movement_clock);
    }
}

void player_slide(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->animation_time);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.2) {
        move_rect(&player->player->rect, create_vector(PLAYER_SLIDE_OFFSET, 0));
        sfClock_restart(player->animation_time);
        player->sprite_nbr++;
    }
    if (player->sprite_nbr == 10) {
        player->sprite_nbr = 0;
        player->slide = sfFalse;
        sfClock_restart(player->movement_clock);
        move_rect_to(&player->player->rect,
            create_vector(PLAYER_RUN_X, PLAYER_RUN_Y),
            create_vector(PLAYER_RUN_OFFSET, 350));
    }
}

void player_run(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->animation_time);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.2) {
        move_rect(&player->player->rect, create_vector(PLAYER_RUN_OFFSET, 0));
        sfClock_restart(player->animation_time);
        player->sprite_nbr++;
    }
    if (player->sprite_nbr == 10) {
        player->sprite_nbr = 0;
        move_rect_to(&player->player->rect,
            create_vector(PLAYER_RUN_X, PLAYER_RUN_Y),
            create_vector(PLAYER_RUN_OFFSET, 350));
        sfClock_restart(player->movement_clock);
    }
}

void player_idle(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->animation_time);
    float sec = time.microseconds / 1000000.0;

    if (sec > 0.2) {
        move_rect(&player->player->rect, create_vector(PLAYER_IDLE_OFFSET, 0));
        sfClock_restart(player->animation_time);
        player->sprite_nbr++;
    }
    if (player->sprite_nbr == 10) {
        player->sprite_nbr = 0;
        move_rect_to(&player->player->rect,
            create_vector(PLAYER_IDLE_X, PLAYER_IDLE_Y),
            create_vector(PLAYER_IDLE_OFFSET, 350));
        sfClock_restart(player->movement_clock);
    }
    sfSprite_setTextureRect(player->player->sprite, player->player->rect);
    sfSprite_move(player->player->sprite, player->player->speed);
}

void move_player(player_t *player)
{
    sfTime time = sfClock_getElapsedTime(player->movement_clock);

    player->movement_time = time.microseconds / 1000000.0;
    if (player->jump == sfTrue) {
        player_jump(player);
    } else if (player->slide == sfTrue) {
        player_slide(player);
    } else {
        player_run(player);
    }
    sfSprite_setTextureRect(player->player->sprite, player->player->rect);
    sfSprite_move(player->player->sprite, player->player->speed);
    player->player->pos = sfSprite_getPosition(player->player->sprite);
    player->player->hitbox.top = player->player->pos.y;
    player->player->hitbox.left = player->player->pos.x + 20;
}