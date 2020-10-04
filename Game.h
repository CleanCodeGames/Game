#pragma once
#include "UI_Manager.h"

class Game : public B {
private:

	UI_Manager m_ui_manager;
	MainMenu m_main_menu;

public:

	Game() : B("init") {
		while (wnd.isOpen())
		{
			System::SystemUpdate();
			m_main_menu.Update();
			while (wnd.pollEvent(event)) {
				CloseEvent();
				m_main_menu.Action();
			}
			wnd.clear();
			m_main_menu.Draw();
			wnd.display();
		}
	}

	~Game() {

	}
};