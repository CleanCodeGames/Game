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
		wnd.setView(wnd.getDefaultView());	// �������� ���������
		m_main_menu.Update();
		wnd.setView(cam);					// ����� �������� ���������
	}

	void Action() {
		wnd.setView(wnd.getDefaultView());	// �������� ���������
		m_main_menu.Action();
		wnd.setView(cam);					// ����� �������� ���������
	}

	void Draw() {
		wnd.setView(wnd.getDefaultView());	// �������� ���������
		m_main_menu.Draw();
		wnd.setView(cam);					// ����� �������� ���������
	}

	~UI_Manager() {

	}
};