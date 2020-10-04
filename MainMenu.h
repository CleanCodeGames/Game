#pragma once
#include "MenuSelectMap.h"

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
	MenuSelectMap m_menu_select_map;

public:

	MainMenu() {
		vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 - 25), v2f(80, 24), -1, color_cell_in, color_cell_out), "Play"));
		vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 - 0), v2f(80, 24), -1, color_cell_in, color_cell_out), "Options"));
		vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 + 25), v2f(80, 24), -1, color_cell_in, color_cell_out), "Quit"));
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
			for (auto& button : vec_button) {
				wnd.setView(wnd.getDefaultView());
				// Экранная обработка
				button->Update();
				// Конец экранной обработки
				wnd.setView(cam);
			}
			break;
		case StateMenu::MAP_SELECT:
			wnd.setView(wnd.getDefaultView());
			// Экранная обработка
			m_menu_select_map.Update();
			// Конец экранной обработки
			wnd.setView(cam);
			break;
		case StateMenu::OPTIONS:
			break;
		default:
			break;
		}
	}

	void Action() {
		switch (m_state)
		{
		case StateMenu::MAIN:
			wnd.setView(wnd.getDefaultView());
			// Экранная обработка
			for (auto& button : vec_button) {
				if (button->Action()) {
					if (button->GetActionId() == "Play") {
						m_menu_select_map.CheckMaps();
						m_state = StateMenu::MAP_SELECT;
					}
					else if (button->GetActionId() == "Options") m_state = StateMenu::OPTIONS;
					else if (button->GetActionId() == "Quit") wnd.close();
				}
			}
			// Конец экранной обработки
			wnd.setView(cam);
			
			break;
		case StateMenu::MAP_SELECT:
			wnd.setView(wnd.getDefaultView());
			// Экранная обработка
			m_menu_select_map.Action();
			// Конец экранной обработки
			wnd.setView(cam);
			break;
		case StateMenu::OPTIONS:
			break;
		default:
			break;
		}
	}

	void Draw() {
		switch (m_state)
		{
		case StateMenu::MAIN:
			wnd.setView(wnd.getDefaultView());
			// Экранная обработка
			for (auto& button : vec_button) {
				button->Draw();
			}
			// Конец экранной обработки
			wnd.setView(cam);
			break;
		case StateMenu::MAP_SELECT:
			wnd.setView(wnd.getDefaultView());
			// Экранная обработка
			m_menu_select_map.Draw();
			// Конец экранной обработки
			wnd.setView(cam);
			break;
		case StateMenu::OPTIONS:
			break;
		default:
			break;
		}
	}

	~MainMenu() {

	}
};