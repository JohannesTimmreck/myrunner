/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** header with strcutures for my_runner
*/

#ifndef _STRUCTURES_
#define _STRUCTURES_

enum object_type
{
    background,
    character,
    spike_a,
};

typedef struct game_object_s game_object_t;

typedef void(*move_objects)(game_object_t *);

struct game_object_s
{
    enum object_type game_object;
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2f pos;
    sfVector2f speed;
    sfIntRect rect;
    sfIntRect hitbox;
    move_objects movement;
};

typedef struct obstacle_s obstacle_t;
struct obstacle_s
{
    game_object_t *obstacle;
    obstacle_t *next;
};

struct map_s
{
    char **map;
    obstacle_t *obstacles;
};
typedef struct map_s map_t;

struct score_s
{
    sfFont *font;
    char *score_num;
    float increase_score;
    int nb_of_increases;
    sfText *text_t;
    sfText *text_n;
    sfClock *score_clock;
};
typedef struct score_s score_t;

struct background_s
{
    game_object_t **background1;
    game_object_t **background2;
};
typedef struct background_s background_t;

struct player_s
{
    game_object_t *player;
    sfClock *animation_time;
    sfClock *movement_clock;
    float movement_time;
    int sprite_nbr;
    sfBool jump;
    sfBool slide;
    sfBool idle;
};
typedef struct player_s player_t;

struct game_assets_s
{
    map_t *map;
    sfClock *movement_time;
};
typedef struct game_assets_s game_assets_t;

struct menu_s
{
    int pos_of_arrow;
    game_object_t **buttons;
    game_object_t *arrow;
    sfFont *font;
    sfText **texts;
};
typedef struct menu_s menu_t;

struct end_screen_s
{
    int pos_of_arrow;
    game_object_t *arrow;
    sfFont *font;
    sfText **texts;
    game_object_t **buttons;
};
typedef struct end_screen_s end_screen_t;

struct basis_s
{
    int gamestatus;
    int swap_to_next_phase;
    score_t *score;
    game_object_t *arrow_sign;
    sfRenderWindow *window;
    player_t *player;
    background_t *backgrounds;
    menu_t *main_menu;
    game_assets_t *assets;
    sfMusic *music;
    end_screen_t *end_screen;
};
typedef struct basis_s basis_t;

#endif