/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** colllision.c
*/

#include "runner.h"

int check_obstacle_on_screen(game_object_t *obstacle)
{
    if (obstacle->pos.x + 128 > 0 && obstacle->pos.x < 1920) {
        return (1);
    } else {
        return (0);
    }
}

int check_point_in_area(sfVector2i point, sfIntRect rect)
{
    if (point.x < rect.left)
        return (0);
    if (point.y < rect.top)
        return (0);
    if (point.x > rect.left + rect.width)
        return (0);
    if (point.y > rect.top + rect.height)
        return (0);
    return (1);
}

int check_for_collision(sfIntRect hitbox_p, sfIntRect hitbox_o)
{
    if (check_point_in_area(create_int_vector(hitbox_o.left, hitbox_o.top),
        hitbox_p) == 1)
        return (1);
    if (check_point_in_area(create_int_vector(hitbox_o.left + hitbox_o.width,
        hitbox_o.top), hitbox_p) == 1)
        return (1);
    if (check_point_in_area(create_int_vector(hitbox_p.left + hitbox_p.width,
        hitbox_p.top), hitbox_o) == 1)
        return (1);
    if (check_point_in_area(create_int_vector(hitbox_p.top + hitbox_p.width,
        hitbox_p.left + hitbox_p.height), hitbox_o) == 1)
        return (1);
    return (0);
}

void manage_collision(basis_t *basis)
{
    obstacle_t *tmp = basis->assets->map->obstacles;
    int check = 0;

    for (; tmp != NULL; tmp = tmp->next) {
            check = check_for_collision(basis->player->player->hitbox,
                tmp->obstacle->hitbox);
        if (check == 1) {
            basis->gamestatus = END_SCREEN_LOSE;
            basis->swap_to_next_phase = 1;
            basis->end_screen = create_end_screen(basis->gamestatus,
                basis->score);
        }
    }
}
