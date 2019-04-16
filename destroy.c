/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** destroy stuff
*/

#include "runner.h"

void destroy_menu(menu_t *menu)
{
    destroy_game_object(menu->arrow);
    for (int i = 0; i < 5; i++) {
        destroy_game_object(menu->buttons[i]);
        sfText_destroy(menu->texts[i]);
    }
    free(menu->texts);
    free(menu->buttons);
    sfFont_destroy(menu->font);
}

void destroy_game_object(game_object_t *game_object)
{
    sfTexture_destroy(game_object->texture);
    sfSprite_destroy(game_object->sprite);
    free(game_object);
}

void destroy_player(player_t *player)
{
    destroy_game_object(player->player);
    sfClock_destroy(player->animation_time);
}
