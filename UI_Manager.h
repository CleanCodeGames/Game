#pragma once
#include "MainMenu.h"

class UI_Manager : public B 
{
private:

	MainMenu m_main_menu;

public:

	UI_Manager() {

	}



	void Update() {
		wnd.setView(wnd.getDefaultView());
		// Экранная обработка

		// Конец экранной обработки
		wnd.setView(cam);
	}

	void Action() {
		wnd.setView(wnd.getDefaultView());
		// Экранная обработка

		// Конец экранной обработки
		wnd.setView(cam);
	}

	void Draw() {

	}

	~UI_Manager() {

	}
};