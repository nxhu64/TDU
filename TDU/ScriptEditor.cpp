#include "Menus.h"
#include "LuaFunctions.h"

#include <mutex>

#include <TextEditor.h>
#include <imgui.h>

ImGuiIO* pIO;
ImGuiStyle* pStyle;

TextEditor pScriptEditor;

std::once_flag fHasInitializedEditor;

void InitEditor()
{
	pIO = &ImGui::GetIO();
	pStyle = &ImGui::GetStyle();

	TextEditor::LanguageDefinition LuaLang = TextEditor::LanguageDefinition::Lua();
	pScriptEditor.SetLanguageDefinition(LuaLang);
}


void TDU::Menus::DrawScriptEditor()
{
	std::call_once(fHasInitializedEditor, InitEditor);

	pIO->MouseDrawCursor = g_FreeCursor;

	if (!g_FreeCursor)
		return;

	ImGui::SetNextWindowPos(ImVec2((pIO->DisplaySize.x / 20 * 2) + pIO->DisplaySize.x / 3, pIO->DisplaySize.y / 20), ImGuiCond_FirstUseEver);
	ImGui::SetNextWindowSize(ImVec2(pIO->DisplaySize.x / 3, pIO->DisplaySize.y / 2), ImGuiCond_FirstUseEver);

	ImGui::Begin("Script editor", 0);

	ImVec2 WindowSize = ImGui::GetContentRegionAvail();
	ImVec2 textSize = ImGui::CalcTextSize("execute", NULL, true);
	ImVec2 size = ImVec2(textSize.x + pStyle->FramePadding.x * 2.0f, textSize.y + pStyle->FramePadding.y * 2.0f);
	ImVec2 childSize(WindowSize.x, WindowSize.y - size.y - pStyle->ItemSpacing.y);

	ImGui::BeginChild("##ScriptExecChild", childSize);
	pScriptEditor.Render("scriptEditor");
	ImGui::EndChild();

	if (ImGui::Button("Run"))
		TDU::Lua::RunScript(pScriptEditor.GetText());

	ImGui::SameLine();

	if (ImGui::Button("Clear"))
		ImGui::OpenPopup("Clear?");

	if (ImGui::BeginPopupModal("Clear?", NULL, ImGuiWindowFlags_AlwaysAutoResize))
	{
		ImGui::Text("Your script will be deleted. \n(This can't be undone).");
		if (ImGui::Button("Ok"))
		{
			pScriptEditor.SetText("");
			ImGui::CloseCurrentPopup();
		}
		ImGui::SameLine();
		if (ImGui::Button("Cancel"))
			ImGui::CloseCurrentPopup();
		ImGui::EndPopup();
	}

	ImGui::End();
}