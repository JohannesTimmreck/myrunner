/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** score
*/

#include "runner.h"

score_t *create_score(void)
{
    score_t *score = malloc(sizeof(score_t));
    sfVector2f pos1 = create_vector(1500, 0);
    sfVector2f pos2 = create_vector(1680, 0);
    char *score_text = "Score:";
    unsigned int size = 60;

    score->font = sfFont_createFromFile(PATH_TO_FONT);
    score->text_t = set_text(score_text, pos1, score->font, size);
    score->score_num = malloc(sizeof(char) * 8);
    score->score_num[7] = '\0';
    for (int i = 0; i < 7; i++)
        score->score_num[i] = '0';
    score->text_n = set_text(score->score_num, pos2, score->font, size);
    score->score_clock = sfClock_create();
    score->increase_score = 0.5;
    score->nb_of_increases = 0;
    return (score);
}

void destroy_score(score_t *score)
{
    sfFont_destroy(score->font);
    sfText_destroy(score->text_t);
    sfText_destroy(score->text_n);
    sfClock_destroy(score->score_clock);
    free(score->score_num);
    free(score);
}

char *add_higher_score(char *str)
{
    if (str[2] > '9') {
        str[2] = '0';
        str[1]++;
    }
    if (str[1] > '9') {
        str[1] = '0';
        str[0]++;
    }
    return (str);
}

char *add_score(char *str)
{
    str[6] = str[6] + 1;
    if (str[6] > '9') {
        str[6] = '0';
        str[5]++;
    }
    if (str[5] > '9') {
        str[5] = '0';
        str[4]++;
    }
    if (str[4] > '9') {
        str[4] = '0';
        str[3]++;
    }
    if (str[3] > '9') {
        str[3] = '0';
        str[2]++;
    }
    str = my_strcpy(str, add_higher_score(str));
    return (str);
}

void modify_score(score_t *score)
{
    sfTime time = sfClock_getElapsedTime(score->score_clock);
    float sec = time.microseconds / 1000000.0;
    int score_nb;

    if (sec > score->increase_score) {
        score->score_num = my_strcpy(score->score_num,
            add_score(score->score_num));
        sfText_setString(score->text_n, score->score_num);
        sfClock_restart(score->score_clock);
        }
    score_nb = my_getnbr(score->score_num);
    if (score_nb > 30 + 100 * score->nb_of_increases) {
        score->increase_score /= 1.5;
        score->nb_of_increases++;
    }
}
