/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** new obstacles
*/

#include "runner.h"

sfIntRect create_rect_for_obst(char type_of_obst)
{
    char *types = "A";
    int width = 128;
    int heigth[] = {SPIKE_A_HEIGTH};
    sfIntRect rect;

    for (int i = 0; types[i] != '\0'; ++i) {
        if (types[i] == type_of_obst) {
            rect = create_rect(0, 0, width, heigth[i]);
            return (rect);
        }
    }
}

obstacle_t *new_obstacle(char type_of_obst, int line, int column)
{
    char *types = "A";
    char *paths[] = {PATH_SPIKE_A};
    int heigth[] = {SPIKE_A_HEIGTH};
    sfVector2f pos = create_vector(1920 + 128 * column, 650 + (line * 40));
    sfVector2f speed = create_vector(-6.0, 0);
    obstacle_t *barrier = malloc(sizeof(obstacle_t));
    sfIntRect rect = create_rect_for_obst(type_of_obst);

    for (int i = 0; types[i] != '\0'; i++) {
        if (types[i] == type_of_obst) {
            barrier->obstacle = create_game_object(paths[i], pos, speed, rect);
            barrier->obstacle->hitbox = create_rect(pos.x, pos.y, 100,
                heigth[i]);
            barrier->obstacle->movement = &move_obstacle;
            barrier->next = NULL;
        }
    }
    return (barrier);
}

obstacle_t *add_to_list(obstacle_t *list, obstacle_t *new)
{
    obstacle_t *tmp = list;

    while (tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = new;
    return (list);
}

obstacle_t *load_new_obstacle(char type, int line, int column, obstacle_t *list)
{
    obstacle_t *new;

    if (type != 'A')
        return (list);
    new = new_obstacle(type, line, column);
    list = add_to_list(list, new);
    return (list);
}

obstacle_t *load_obstacles(char **map)
{
    obstacle_t *begin = malloc(sizeof(obstacle_t));
    obstacle_t *list;

    begin->next = NULL;
    for (int y = 0; y < 5; y++) {
        for (int x = 0; map[y][x] != 'X'; x++) {
            begin = load_new_obstacle(map[y][x], y, x, begin);
        }
    }
    list = begin->next;
    free(begin);
    return (list);

}