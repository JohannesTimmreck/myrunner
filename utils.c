/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** utils.c
*/

#include "runner.h"

int my_strlen(char *str)
{
    int len = 0;

    for (int i = 0; str[i] != '\0'; ++i)
        len++;
    return (len);
}

sfText *set_text(char *str, sfVector2f pos, sfFont *font, unsigned int size)
{
    sfText *text = sfText_create();

    sfText_setString(text, str);
    sfText_setPosition(text, pos);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, size);
    return (text);
}

sfMusic *set_music(char *path_to_music, int volume)
{
    sfMusic *music = sfMusic_createFromFile(path_to_music);

    sfMusic_setLoop(music, sfTrue);
    sfMusic_setVolume(music, volume);
    sfMusic_play(music);
    return (music);
}

sfVector2i create_int_vector(int nb1, int nb2)
{
    sfVector2i vector;

    vector.x = nb1;
    vector.y = nb2;
    return (vector);
}