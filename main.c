/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** main
*/

#include "runner.h"

void background_movement(background_t *background)
{
    for (int i = 0; i <= 4; i++) {
        background->background1[i]->movement(background->background1[i]);
        background->background2[i]->movement(background->background2[i]);
    }
}

void game_loop(basis_t *basis, sfEvent *event)
{
    while (sfRenderWindow_isOpen(basis->window)) {
        sfRenderWindow_display(basis->window);
        if (basis->gamestatus == MAIN_MENU) {
            manage_main_menu_screen(basis, event);
        } else if (basis->gamestatus == RUNNING) {
            manage_game(basis, event);
        } else {
            display_endscreen(basis);
            end_screen_events(basis, event);
        }
        if (basis->swap_to_next_phase == 1)
            prepare_next_game_phase(basis);
    }
}

int main(int ac, char **av)
{
    basis_t *basis;
    sfEvent *event;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h' && av[1][2] == '\0') {
        display_usage();
        return (0);
    }
    basis = init_basis();
    event = malloc(sizeof(sfEvent));
    game_loop(basis, event);
    free(event);
    destroy_basis(basis);
    return (0);
}
