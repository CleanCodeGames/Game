#pragma once
#include "Button.h"
#include "TextBox.h"

enum class StateMenu {
	MAIN = 0u,
	MAP_SELECT = 1u,
	OPTIONS = 2u
};

class MainMenu : public B
{
private:

	StateMenu m_state = StateMenu::MAIN;

public:

	MainMenu() {

	}

	void Update() {
		switch (m_state)
		{
		case StateMenu::MAIN:
			break;
		case StateMenu::MAP_SELECT:
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
			break;
		case StateMenu::MAP_SELECT:
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
			break;
		case StateMenu::MAP_SELECT:
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