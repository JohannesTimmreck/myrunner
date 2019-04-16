/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** map
*/

#include "runner.h"

char **map_to_array(char *path_to_map)
{
    int fd = open(path_to_map, O_RDONLY);
    char **map = malloc(sizeof(char *) * 7);

    if (fd == -1) {
        write(1, "please insert other file\n", 25);
        return (NULL);
    } else if (map == NULL) {
        return (NULL);
    }
    for (long unsigned int i = 0; i < 6; i++) {
        map[i] = get_next_line(fd);
    }
    return (map);
}

map_t *load_map(char *path_to_map)
{
    map_t *map = malloc(sizeof(map_t));
    map->map = map_to_array(path_to_map);

    map->obstacles = load_obstacles(map->map);
    return (map);
}

void destroy_map(map_t *map)
{
    destroy_obstacles(map->obstacles);
    for (int i = 0; i < 6; i++)
        free(map->map[i]);
    free(map->map);
    free(map);
}
