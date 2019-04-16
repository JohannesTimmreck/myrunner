/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** create stuff
*/

#include "runner.h"

sfVector2f create_vector(float nb1, float nb2)
{
    sfVector2f vector;

    vector.x = nb1;
    vector.y = nb2;
    return (vector);
}

sfRenderWindow *create_window(unsigned int width, unsigned int height)
{
    sfRenderWindow *window;
    sfVideoMode video_mode;
    char *name = "RUNNING SIMULATOR";

    video_mode.width = width;
    video_mode.height = height;
    video_mode.bitsPerPixel = 32;

    window = sfRenderWindow_create(video_mode, name, sfDefaultStyle, NULL);
    return (window);
}

game_object_t *create_game_object(char const *path_to_sprite, sfVector2f pos,
    sfVector2f speed, sfIntRect rect)
{
    game_object_t *game_object = malloc(sizeof(game_object_t));
    game_object->texture = sfTexture_createFromFile(path_to_sprite, NULL);
    game_object->sprite = sfSprite_create();
    game_object->pos = pos;
    game_object->rect = rect;
    game_object->speed = speed;
    sfSprite_setTexture(game_object->sprite, game_object->texture, sfTrue);
    sfSprite_setTextureRect(game_object->sprite, game_object->rect);
    sfSprite_setPosition(game_object->sprite, game_object->pos);
    return (game_object);
}

player_t *create_player(void)
{
    player_t *player = malloc(sizeof(player_t));
    sfVector2f pos = create_vector(300, 590);
    sfVector2f speed = create_vector(0, 0);
    sfIntRect rect = create_rect(0, 0, PLAYER_IDLE_OFFSET, 350);
    player->player = create_game_object(PATH_PLAYER, pos, speed, rect);
    player->player->hitbox = create_rect(pos.x, pos.y, PLAYER_IDLE_OFFSET - 40, 330);
    player->player->game_object = character;
    player->animation_time = sfClock_create();
    player->movement_clock = sfClock_create();
    player->movement_time = 0;
    player->sprite_nbr = 0;
    player->jump = sfFalse;
    player->slide = sfFalse;
    return (player);
}