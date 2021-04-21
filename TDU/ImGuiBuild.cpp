/*
	weird way to get imgui to compile without having to add it inside the project folder, so that it work as a git submodule
	this is probably not the right way to do this lol, but it works
	if anyone knows a better way to do this, please do let me know
*/

#include <imgui.cpp>
#include <imgui_widgets.cpp>
#include <imgui_tables.cpp>
#include <imgui_draw.cpp>
#include <imgui_demo.cpp>

#define GLEW_STATIC
#include <GL/glew.h>
#include <gl/GL.h>

#define IMGUI_IMPL_OPENGL_LOADER_GLEW

#include <backends/imgui_impl_opengl3.cpp>
#include <backends/imgui_impl_win32.cpp>
