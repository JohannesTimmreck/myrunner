/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** background functions
*/

#include "runner.h"

void move_background(game_object_t *background)
{
    sfSprite_move(background->sprite, background->speed);
    background->pos = sfSprite_getPosition(background->sprite);
    if (background->pos.x + background->speed.x < -1920) {
        background->pos.x = 1920;
        sfSprite_setPosition(background->sprite, background->pos);
    }
    background->pos = sfSprite_getPosition(background->sprite);
}

game_object_t *create_background_layer(int num_layer, int num_bg)
{
    char *paths[] = {PATH_LAYER1, PATH_LAYER2, PATH_LAYER3, PATH_LAYER4,
        PATH_LAYER5};
    sfVector2f pos[2];
    sfIntRect rect = create_rect(0, 0, 1920, 1080);
    game_object_t *layer;
    pos[0] = create_vector(0, 0);
    pos[1] = create_vector(1920, 0);
    sfVector2f speed = create_vector(0, 0);
    layer = create_game_object(paths[num_layer], pos[num_bg], speed, rect);
    layer->game_object = background;
    layer->movement = &move_background;
    layer->movement = &move_background;
    return (layer);
}

background_t *create_background(void)
{
    background_t *bg = malloc(sizeof(background_t));
    bg->background1 = malloc(sizeof(game_object_t) * 6);
    bg->background2 = malloc(sizeof(game_object_t) * 6);

    for (int i = 0; i <= 4; i++) {
        bg->background1[i] = create_background_layer(i, 0);
        bg->background2[i] = create_background_layer(i, 1);
    }
    bg->background1[5] = NULL;
    bg->background2[5] = NULL;
    bg->background1[0]->speed.x = 0;
    bg->background2[0]->speed.x = 0;
    return (bg);
}

void destroy_background(background_t *bg)
{
    for (int i = 0; i <= 4; i++) {
        destroy_game_object(bg->background1[i]);
        destroy_game_object(bg->background2[i]);
    }
    free(bg);
}
