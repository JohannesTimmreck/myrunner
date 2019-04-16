/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** handle obstacles
*/

#include "runner.h"

int check_obstacle_left_of_screen(game_object_t *obstacle)
{
    if (obstacle->pos.x + 128 <= 0) {
        return (1);
    } else {
        return (0);
    }
}

void move_obstacle(game_object_t *obstacle)
{
        sfSprite_move(obstacle->sprite, obstacle->speed);
        obstacle->pos = sfSprite_getPosition(obstacle->sprite);
        obstacle->hitbox.top = obstacle->pos.y + 10;
        obstacle->hitbox.left = obstacle->pos.x + 10;
}

void manage_obstacles(map_t *map)
{
    obstacle_t *tmp = map->obstacles->next;

    while (tmp != NULL) {
        tmp->obstacle->movement(tmp->obstacle);
        tmp = tmp->next;
    }
}

void destroy_obstacles(obstacle_t *list)
{
    obstacle_t *tmp = list->next;

    for (; tmp != NULL; tmp = tmp->next) {
        destroy_game_object(list->obstacle);
        free(list);
        list = tmp;
    }
    destroy_game_object(list->obstacle);
    free(list);
}
