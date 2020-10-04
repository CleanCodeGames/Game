#pragma once
#include "Button.h"
#include "TextBox.h"

class MenuOptions : public B
{
private:

	vector<unique_ptr<AbstractButton>> vec_button;

public:

	MenuOptions() {

	}

	void Update() {
		for (auto& button : vec_button) {
			button->Update();
		}
	}

	void Action() {
		for (auto& button : vec_button) {
			button->Action();
		}
	}

	void Draw() {
		for (auto& button : vec_button) {
			button->Draw();
		}
	}

	~MenuOptions() {

	}
};