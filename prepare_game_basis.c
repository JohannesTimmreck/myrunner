/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** prepare game & basis
*/

#include "runner.h"

basis_t *init_basis(void)
{
    basis_t *basis = malloc(sizeof(basis_t));
    sfVector2f pos = create_vector(150, 737);
    sfVector2f speed = create_vector(GROUND_SPEED, 0);
    sfIntRect rect = create_rect(0, 0, 84, 87);

    basis->swap_to_next_phase = 0;
    basis->window = create_window(WINDOW_WIDTH, WINDOW_HEIGHT);
    sfRenderWindow_setFramerateLimit(basis->window, 120);
    basis->music = set_music(PATH_MENU_MUSIC, 50);
    basis->arrow_sign = create_game_object(PATH_TO_ARROW_SIGN, pos, speed,
        rect);
    basis->arrow_sign->movement = &move_obstacle;
    basis->main_menu = create_main_menu();
    sfSprite_setScale(basis->arrow_sign->sprite,  create_vector(2, 2));
    basis->player = create_player();
    basis->backgrounds = create_background();
    basis->assets = NULL;
    basis->gamestatus = MAIN_MENU;
    return (basis);
}

void destroy_basis(basis_t *basis)
{
    destroy_game_object(basis->arrow_sign);
    destroy_background(basis->backgrounds);
    destroy_player(basis->player);
    sfMusic_destroy(basis->music);
    sfRenderWindow_destroy(basis->window);
    free(basis);
}

void set_background_speed(game_object_t *background, int num_layer)
{
    sfVector2f speed = create_vector(-4 - (0.5 * num_layer), 0);

    background->speed = speed;
}

game_assets_t *create_assets(char *map_path)
{
    game_assets_t *assets = malloc(sizeof(game_assets_t));

    assets->map = load_map(map_path);
    assets->movement_time = sfClock_create();
    return (assets);
}

void prepare_game(basis_t *basis, char *map_path)
{
    basis->gamestatus = RUNNING;
    basis->assets = create_assets(map_path);
    basis->score = create_score();
    move_rect_to(&basis->player->player->rect,
        create_vector(PLAYER_RUN_X, PLAYER_RUN_Y),
        create_vector(PLAYER_RUN_OFFSET, 350));
    for (int i = 0; basis->backgrounds->background1[i] != NULL; i++)
        set_background_speed(basis->backgrounds->background1[i], i);
    for (int i = 0; basis->backgrounds->background1[i] != NULL; i++)
        set_background_speed(basis->backgrounds->background2[i], i);
    sfMusic_destroy(basis->music);
    basis->music = set_music(PATH_GAME_MUSIC, 50);
}
