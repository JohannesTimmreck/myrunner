/*
** EPITECH PROJECT, 2018
** my_runner
** File description:
** header with macros for my_runner
*/

#ifndef _MACROS_
#define _MACROS_

#define MAIN_MENU (0)
#define RUNNING (1)
#define PAUSE_MENU (2)
#define END_SCREEN_WIN (3)
#define END_SCREEN_LOSE (4)

#define WINDOW_HEIGHT (1080)
#define WINDOW_WIDTH (1920)

#define PLAYER_IDLE_X (0)
#define PLAYER_IDLE_Y (0)
#define PLAYER_IDLE_OFFSET (208)

#define PLAYER_RUN_X (0)
#define PLAYER_RUN_Y (350)
#define PLAYER_RUN_OFFSET (270)

#define PLAYER_JUMP_X (0)
#define PLAYER_JUMP_Y (2 * 350)
#define PLAYER_JUMP_OFFSET (265)

#define PLAYER_SLIDE_X (0)
#define PLAYER_SLIDE_Y (3 * 350)
#define PLAYER_SLIDE_OFFSET (257)

#define SPIKE_A_HEIGTH (123)

#define GROUND_SPEED (-7.5)

#define PATH_PLAYER ("media/visual/character_animation.png")
#define PATH_LAYER1 ("media/visual/layer1.png")
#define PATH_LAYER2 ("media/visual/layer2.png")
#define PATH_LAYER3 ("media/visual/layer3.png")
#define PATH_LAYER4 ("media/visual/layer4.png")
#define PATH_LAYER5 ("media/visual/layer5.png")

#define PATH_SPIKE_A ("media/visual/tiles/spike_A.png")

#define PATH_TO_BUTTON ("media/visual/tiles/StoneBlock.png")
#define PATH_TO_ARROW_SIGN ("media/visual/tiles/SignArrow.png")
#define PATH_TO_ARROW ("media/visual/Arrows.png")

#define PATH_TO_MAP1 ("maps/map1")
#define PATH_TO_MAP2 ("maps/map2")
#define PATH_TO_MAP3 ("maps/map3")

#define PATH_TO_FONT ("media/visual/arabian_font.ttf")

#define PATH_MENU_MUSIC ("media/audio/Ibn_Al-Noor.ogg")
#define PATH_GAME_MUSIC ("media/audio/Old_Road.ogg")

#endif