#ifndef GUI_H
#define GUI_H

#include <ignite.h>

typedef struct gui {

} gui;

void gui_start(gui* gui);
void gui_draw(gui* gui, const ig_window* window, const ig_keyboard* keyboard, const ig_mouse* mouse, bool* close_requested);
void gui_end(gui* gui);

#endif