/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** create main menu
*/

#include "runner.h"

game_object_t **create_main_menu_buttons(void)
{
    game_object_t **buttons = malloc(sizeof(game_object_t *) * 6);
    sfVector2f pos;
    sfVector2f speed = create_vector(0, 0);
    sfIntRect rect = create_rect(0, 0, 101, 99);

    buttons[5] = NULL;
    for (int i = 0; i < 5; i++) {
        pos = create_vector((WINDOW_WIDTH - (101 * 5))/2, 100 + i * 140);
        if (i == 0)
            pos = create_vector((WINDOW_WIDTH - (101 * 11))/2, 100);
        buttons[i] = create_game_object(PATH_TO_BUTTON, pos, speed, rect);
        sfSprite_setScale(buttons[i]->sprite, create_vector(5, 1));
    }
    sfSprite_setScale(buttons[0]->sprite, create_vector(11, 1.25));
    return (buttons);
}

sfText **create_main_menu_texts(sfFont *font)
{
    char *strings[] = {"RUNNING SIMULATOR", "LEVEL 1", "LEVEL 2",
        "LEVEL 3", "EXIT"};
    sfText **texts = malloc(sizeof(sfText *) * 6);
    sfVector2f pos;

    for (int i = 1; i <= 4; i++) {
        pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2) + 120,
            110 + i * 140);
        if (i == 4)
            pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2) + 170,
                110 + i * 140);
        texts[i] = set_text(strings[i], pos, font, 60);
    }
    pos = create_vector(((WINDOW_WIDTH - (101 * 11))/2) + 100, 110);
    texts[0] = set_text(strings[0], pos, font, 80);
    texts[5] = NULL;
    return (texts);
}

menu_t *create_main_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfVector2f pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2) - 150, 220);
    sfVector2f speed = create_vector(0, 0);
    sfIntRect rect = create_rect(168, 172, 400-172, 315-168);

    menu->pos_of_arrow = 0;
    menu->buttons = create_main_menu_buttons();
    menu->font = sfFont_createFromFile(PATH_TO_FONT);
    menu->texts = create_main_menu_texts(menu->font);
    menu->arrow = create_game_object(PATH_TO_ARROW, pos, speed, rect);
    return (menu);
}