#pragma once
#include "UI_Manager.h"

class Game : public B {
private:

	UI_Manager m_ui_manager;

public:

	Game() : B("init") {
		while (wnd.isOpen())
		{
			Update();
			Action();
			Draw();
		}
	}

	void Update() {
		System::SystemUpdate();
		m_ui_manager.Update();
	}

	void Action() {
		while (wnd.pollEvent(event)) {
			CloseEvent();
			m_ui_manager.Action();
		}
	}

	void Draw() {
		wnd.clear();
		m_ui_manager.Draw();
		wnd.display();
	}

	~Game() {

	}
};