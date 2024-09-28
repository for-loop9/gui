#ifndef IG_WINDOW_H
#define IG_WINDOW_H

#include <GLFW/glfw3.h>
#include <stdbool.h>
#include "../math/ig_ivec2.h"

typedef struct ig_keyboard ig_keyboard;
typedef struct ig_mouse ig_mouse;
typedef struct ig_window ig_window;

typedef struct user_data {
	ig_window* window;
	ig_keyboard* keyboard;
	ig_mouse* mouse;
} user_data;

typedef struct ig_window {
	GLFWwindow* native_handle;
	ig_ivec2 dim;
	ig_ivec2 last_dim;
	user_data ud;
	bool resize_requested;
} ig_window;

ig_window* ig_window_create_asp(float asp_ratio, const char* title, const GLFWimage* icons, int icons_count);
ig_window* ig_window_create(const ig_ivec2* dim, const char* title, int full_screen, int monitor, const GLFWimage* icons, int icons_count);

void ig_window_input(ig_window* window);
void ig_window_set_fullscreen(ig_window* window, bool fullscreen);
int ig_window_closed(ig_window* window);
int ig_window_keyboard_key_down(ig_window* window, int key);
int ig_window_mouse_button_down(ig_window* window, int button);

void ig_window_destroy(ig_window* window);

#endif