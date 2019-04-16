/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** create endscreen
*/

#include "runner.h"

sfText **create_end_screen_text(sfFont *font, int gamestatus)
{
    sfText **texts = malloc(sizeof(sfText *) * 4);
    char *strings[] = {"SET GAME STATUS HERE", "RETURN TO MENU", "EXIT"};

    sfVector2f pos;

    texts[3] = NULL;
    for (int i = 1; i < 3; i++) {
        pos = create_vector(100, 100 + 100 * i);
        texts[i] = set_text(strings[i], pos, font, 60);
    sfText_setColor(texts[i], sfBlack);
    }
    if (gamestatus == END_SCREEN_WIN) {
        texts[0] = set_text("YOU WON", create_vector(100, 100), font, 180);
    } else {
        texts[0] = set_text("YOU LOST", create_vector(100, 100), font, 180);
    }
    sfText_setColor(texts[0], sfBlack);
    return (texts);
}

game_object_t **create_endscreen_buttons(void)
{
    game_object_t **buttons = malloc(sizeof(game_object_t *) * 3);
    sfVector2f pos = create_vector(100, 200);
    sfVector2f speed = create_vector(0, 0);
    sfIntRect rect = create_rect(0, 0, 101, 99);

    buttons[0] = create_game_object(PATH_TO_BUTTON, pos, speed, rect);
    pos = create_vector(100, 300);
    buttons[1] = create_game_object(PATH_TO_BUTTON, pos, speed, rect);
    buttons[2] = NULL;
    sfSprite_setScale(buttons[0]->sprite, create_vector(5, 1));
    sfSprite_setScale(buttons[1]->sprite, create_vector(5, 1));
    return (buttons);
}

void set_endscreen_position(end_screen_t *end_screen, score_t *score)
{
    sfVector2f pos = create_vector(((WINDOW_WIDTH)/4), 70);

    sfText_setPosition(end_screen->texts[0], pos);
    pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2) + 20, 280);
    sfText_setColor(score->text_t, sfBlack);
    sfText_setPosition(score->text_t, pos);
    pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2) + 190, 280);
    sfText_setColor(score->text_n, sfBlack);
    sfText_setPosition(score->text_n, pos);
    pos = create_vector(((WINDOW_WIDTH - (101 * 7.5))/2) + 70, 410);
    sfText_setPosition(end_screen->texts[1], pos);
    pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2) + 175, 560);
    sfText_setPosition(end_screen->texts[2], pos);
    pos = create_vector(((WINDOW_WIDTH - (101 * 7.5))/2), 400);
    sfSprite_setPosition(end_screen->buttons[0]->sprite, pos);
    pos = create_vector(7.5, 1);
    sfSprite_setScale(end_screen->buttons[0]->sprite, pos);
    pos = create_vector(((WINDOW_WIDTH - (101 * 5))/2), 550);
    sfSprite_setPosition(end_screen->buttons[1]->sprite, pos);
}

end_screen_t *create_end_screen(int gamestatus, score_t *score)
{
    end_screen_t *end_screen = malloc(sizeof(end_screen_t));
    sfVector2f pos = create_vector(((WINDOW_WIDTH - (101 * 7.5))/2) - 150, 390);
    sfVector2f speed = create_vector(0, 0);
    sfIntRect rect = create_rect(168, 172, 400-172, 315-168);

    end_screen->pos_of_arrow = 0;
    end_screen->arrow = create_game_object(PATH_TO_ARROW, pos, speed, rect);
    end_screen->font = sfFont_createFromFile(PATH_TO_FONT);
    end_screen->texts = create_end_screen_text(end_screen->font, gamestatus);
    end_screen->buttons = create_endscreen_buttons();
    set_endscreen_position(end_screen, score);
    return (end_screen);
}