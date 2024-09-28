#include "gui.h"

#define CIMGUI_DEFINE_ENUMS_AND_STRUCTS
#include "external/cimgui/cimgui.h"

void gui_start(gui* gui) {
}

void gui_draw(gui* gui, const ig_window* window, const ig_keyboard* keyboard, const ig_mouse* mouse, bool* close_requested) {
	const ImGuiViewport* viewport = igGetMainViewport();
	igSetNextWindowPos(viewport->WorkPos, ImGuiCond_None, (ImVec2) {});
	igSetNextWindowSize(viewport->WorkSize, ImGuiCond_None);
	igSetNextWindowViewport(viewport->ID);
	igPushStyleVar_Vec2(ImGuiStyleVar_WindowPadding, (ImVec2) {});
	igPushStyleVar_Float(ImGuiStyleVar_WindowRounding, 0.0f);
	igPushStyleVar_Float(ImGuiStyleVar_WindowBorderSize, 0.0f);

	igBegin("dockspace_win", NULL,
		ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking | ImGuiWindowFlags_NoTitleBar |
		ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
		ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus);
	igPopStyleVar(3);
	if (igBeginMenuBar()) {
		if (igBeginMenu("File", true)) {
			if (igMenuItem_Bool("Exit", "Q", false, true)) {
				*close_requested = true;
			}
			igEndMenu();
		}
		if (igBeginMenu("Edit", false))
			igEndMenu();
		
		igEndMenuBar();
	}
	ImGuiID dockspace_id = igGetID_Str("dockspace");
	igDockSpace(dockspace_id, (ImVec2) {}, ImGuiDockNodeFlags_PassthruCentralNode, NULL);
	igEnd();

	igShowDemoWindow(NULL);

	// if (ig_keyboard_key_pressed(keyboard, GLFW_KEY_D)) {
	// 	igDockBuilderRemoveNode(dockspace_id);
	// 	igDockBuilderAddNode(dockspace_id, ImGuiDockNodeFlags_DockSpace);
	// 	igDockBuilderSetNodeSize(dockspace_id, viewport->WorkSize);
	// 	ImGuiID demo_id = igDockBuilderSplitNode(dockspace_id, ImGuiDir_Left, 0.2f, NULL, &dockspace_id);
	// 	igDockBuilderDockWindow("Dear ImGui Demo", demo_id);
	// }
}

void gui_end(gui* gui) {
}