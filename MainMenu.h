#pragma once
#include "MenuMapSelect.h"
#include "MenuOptions.h"

enum class StateMenu {
	MAIN = 0u,
	MAP_SELECT = 1u,
	OPTIONS = 2u
};

class MainMenu : public B
{
private:

	StateMenu m_state = StateMenu::MAIN;
	vector<unique_ptr<AbstractButton>> vec_button;
	MenuMapSelect m_menu_map_select;
	MenuOptions m_menu_options;

public:

	MainMenu() {
		vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 - 25), v2f(80, 24), Color(100,100,100)), "Play"));
		vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 - 0), v2f(80, 24), Color(100, 100, 100)), "Options"));
		vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 + 25), v2f(80, 24), Color(100, 100, 100)), "Quit"));
	}

	StateMenu GetState() const {
		return m_state;
	}

	void SetState(StateMenu state) {
		m_state = state;
	}

	void Update() {
		switch (m_state)
		{
			case StateMenu::MAIN:
				for (auto& button : vec_button)
					button->Update();
				break;
			case StateMenu::MAP_SELECT:
				m_menu_map_select.Update();
				break;
			case StateMenu::OPTIONS:
				m_menu_options.Update();
				break;
			default: break;
		}
	}

	void Action() {
		switch (m_state)
		{
			case StateMenu::MAIN:
				for (auto& button : vec_button) {
					if (button->Action()) {
						if (button->GetActionId() == "Play") {
							m_menu_map_select.CheckMaps();
							m_state = StateMenu::MAP_SELECT;
						}
						else if (button->GetActionId() == "Options") m_state = StateMenu::OPTIONS;
						else if (button->GetActionId() == "Quit") wnd.close();
					}
				}
				
				break;
			case StateMenu::MAP_SELECT:
				m_menu_map_select.Action();
				break;
			case StateMenu::OPTIONS:
				m_menu_options.Action();
				break;
		}
	}

	void Draw() {
		switch (m_state)
		{
			case StateMenu::MAIN:
				for (auto& button : vec_button)
					button->Draw();
				break;
			case StateMenu::MAP_SELECT:
				m_menu_map_select.Draw();
				break;
			case StateMenu::OPTIONS:
				m_menu_options.Draw();
				break;
		}
	}

	~MainMenu() {

	}
};