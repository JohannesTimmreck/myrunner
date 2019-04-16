/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** header with functions for my_runner
*/

#ifndef _FUNCTIONS_
#define _FUNCTIONS_

////int_to_str.c
char *int_to_str(int nb, char *str);
////my_getnbr.c
int my_getnbr(char *str);
////my_strcpy.c
char *my_strcpy(char *dest, char *src);

////background.c
void move_background(game_object_t *background);
game_object_t *create_background_layer(int num_layer, int num_bg);
background_t *create_background(void);
void destroy_background(background_t *bg);

////rect.c
sfIntRect create_rect(int top, int left, int width, int height);
void move_rect(sfIntRect *rect, sfVector2f offset);
void move_rect_to(sfIntRect *rect, sfVector2f new_pos, sfVector2f bottom_left);

////player_movement.c
void player_jump(player_t *player);
void player_slide(player_t *player);
void player_run(player_t *player);
void player_idle(player_t *player);
void move_player(player_t *player);

////create.c
sfVector2f create_vector(float nb1, float nb2);
sfRenderWindow *create_window(unsigned int width, unsigned int height);
game_object_t *create_game_object(char const *path_to_sprite, sfVector2f pos,
    sfVector2f speed, sfIntRect rect);
player_t *create_player(void);

////create_main_menu.c
game_object_t **create_main_menu_buttons(void);
sfText **create_main_menu_texts(sfFont *font);
menu_t *create_main_menu(void);


////map.c
char **map_to_array(char *path_to_map);
map_t *load_map(char *path_to_map);
void destroy_map(map_t *map);

////new_obstacles.c
sfIntRect create_rect_for_obst(char type_of_obst);
obstacle_t *new_obstacle(char type_of_obst, int line, int column);
obstacle_t *add_to_list(obstacle_t *list, obstacle_t *new);
obstacle_t *load_new_obstacle(char type, int line, int column,
    obstacle_t *list);
obstacle_t *load_obstacles(char **map);

////manage_obstacles.c
int check_obstacle_left_of_screen(game_object_t *obstacle);
void move_obstacle(game_object_t *obstacle);
void manage_obstacles(map_t *map);
void destroy_obstacles(obstacle_t *list);

////score.c
score_t *create_score(void);
void destroy_score(score_t *score);
char *add_higher_score(char *str);
char *add_score(char *str);
void modify_score(score_t *score);

////destroy.c
void destroy_menu(menu_t *menu);
void destroy_game_object(game_object_t *game_object);
void destroy_player(player_t *player);

////collision.c
int check_obstacle_on_screen(game_object_t *obstacle);
int check_point_in_area(sfVector2i point, sfIntRect rect);
int check_for_collision(sfIntRect hitbox_p, sfIntRect hitbox_o);
void manage_collision(basis_t *basis);

////manage_main_menu.c
void move_arrow_down(basis_t *basis);
void move_arrow_up(basis_t *basis);
void manage_action_main_menu(basis_t *basis, sfKeyEvent event);
void analize_events_main_menu(basis_t *basis, sfEvent *event);
void manage_main_menu_screen(basis_t *basis, sfEvent *event);

////game_loop.c
void manage_action_ingame(basis_t *basis, sfKeyEvent event);
void analize_events_ingame(basis_t *basis, sfEvent *event);
void check_for_win(basis_t *basis);
void draw_game(basis_t *basis);
void manage_game(basis_t *basis, sfEvent *event);

////prepare_game&basis.c
void set_background_speed(game_object_t *background, int num_layer);
basis_t *init_basis(void);
void destroy_basis(basis_t *basis);
game_assets_t *create_assets(char *map_path);
void prepare_game(basis_t *basis, char *map_path);

////usage.c
void display_usage_borders(void);
void display_usage(void);

////create_endscreen.c
sfText **create_end_screen_text(sfFont *font, int gamestatus);
game_object_t **create_endscreen_buttons(void);
void set_endscree_position(end_screen_t *end_screen, score_t *score);
end_screen_t *create_end_screen(int gamestatus, score_t *score);

////manage_endscreen.c
void display_endscreen(basis_t *basis);
void move_arrow_down_end_screen(basis_t *basis);
void move_arrow_up_end_screen(basis_t *basis);
void manage_action_end_screen(basis_t *basis, sfKeyEvent event);
void end_screen_events(basis_t *basis, sfEvent *event);

////prepare_next_game_phase.c
void destroy_assets(game_assets_t *assets);
void reset_main_menu(basis_t *basis);
void destroy_end_screen(end_screen_t *end_screen);
void prepare_next_game_phase(basis_t *basis);

////utils.c
int my_strlen(char *str);
sfText *set_text(char *str, sfVector2f pos, sfFont *font, unsigned int size);
sfMusic *set_music(char *path_to_music, int volume);
sfVector2i create_int_vector(int nb1, int nb2);

////main.c
void background_movement(background_t *background);
void destroy_assets(game_assets_t *assets);
end_screen_t *create_end_screen(int gamestatus, score_t *score);

#endif