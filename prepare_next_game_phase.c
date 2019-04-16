/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** prepare next game phase
*/

#include "runner.h"

void destroy_assets(game_assets_t *assets)
{
    destroy_map(assets->map);
    free(assets);
}

void reset_main_menu(basis_t *basis)
{
    sfVector2f pos = create_vector(150, 737);

    basis->gamestatus = MAIN_MENU;
    basis->main_menu = create_main_menu();
    sfMusic_destroy(basis->music);
    basis->music = set_music(PATH_MENU_MUSIC, 50);
    sfSprite_setPosition(basis->arrow_sign->sprite, pos);
    destroy_player(basis->player);
    basis->player = create_player();
}

void destroy_end_screen(end_screen_t *end_screen)
{
    destroy_game_object(end_screen->arrow);
    destroy_game_object(end_screen->buttons[0]);
    destroy_game_object(end_screen->buttons[1]);
    free(end_screen->buttons);
    sfFont_destroy(end_screen->font);
    sfText_destroy(end_screen->texts[0]);
    sfText_destroy(end_screen->texts[1]);
    sfText_destroy(end_screen->texts[2]);
    free(end_screen->texts);
    free(end_screen);
}

void prepare_next_game_phase(basis_t *basis)
{
    char *maps[] = {PATH_TO_MAP1, PATH_TO_MAP2, PATH_TO_MAP3};

    if (basis->gamestatus == MAIN_MENU) {
        destroy_score(basis->score);
        destroy_end_screen(basis->end_screen);
        if (sfRenderWindow_isOpen(basis->window))
            reset_main_menu(basis);
    } else if (basis->gamestatus == RUNNING) {
        destroy_menu(basis->main_menu);
        if (sfRenderWindow_isOpen(basis->window))
            prepare_game(basis, maps[basis->main_menu->pos_of_arrow]);
    } else {
        destroy_assets(basis->assets);
        if (sfRenderWindow_isOpen(basis->window))
            basis->end_screen = create_end_screen(basis->gamestatus,
                basis->score);
    }
    basis->swap_to_next_phase = 0;
}