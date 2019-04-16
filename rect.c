/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** rectangle functions
*/

#include "runner.h"

sfIntRect create_rect(int top, int left, int width, int height)
{
    sfIntRect rect;

    rect.top = top;
    rect.left = left;
    rect.width = width;
    rect.height = height;
    return (rect);
}

void move_rect(sfIntRect *rect, sfVector2f offset)
{
    rect->left += offset.x;
    rect->top += offset.y;
}

void move_rect_to(sfIntRect *rect, sfVector2f new_pos, sfVector2f bottom_left)
{
    rect->left = new_pos.x;
    rect->top = new_pos.y;
    rect->width = bottom_left.x;
    rect->height = bottom_left.y;
}
