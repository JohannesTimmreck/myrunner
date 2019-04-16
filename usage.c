/*
** EPITECH PROJECT, 2018
** my runner
** File description:
** usage
*/

#include "runner.h"

void display_usage_borders(void)
{
    write(1, "\n", 1);
    for (int i = 0; i < 80; i++)
        write(1, "-", 1);
    write(1, "\n\n", 2);
}

void display_usage(void)
{
    write(1, "\nUSAGE:\n", 8);
    display_usage_borders();
    write(1, "CONTOLS MENU\n", 13);
    write(1, "\tnavigate in the menu with the arrow keys\n", 42);
    write(1, "\tto select an option press enter or the right arrow\n", 52);
    write(1, "\nCONTOLS IN GAME\n", 17);
    write(1, "\tpress Space to jump or s to slide\n", 35);
    display_usage_borders();
    write(1, "GOAL\n", 5);
    write(1, "\tavoid the obstacles by jumping over them ", 42);
    write(1, "or sliding beneath them\n\tin reach the end of the map\n", 54);
    display_usage_borders();
}