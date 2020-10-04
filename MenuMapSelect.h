#pragma once
#include "Button.h"
#include "TextBox.h"

class MenuMapSelect : public B
{
private:

	vector<unique_ptr<AbstractButton>> vec_button;
	vector<string> vec_map_list;

	static bool SortABC(string& x, string& y)
	{
		string x1, y1;
		for (auto& a : x) x1 += tolower(a);
		for (auto& b : y) y1 += tolower(b);
		return x1 < y1;
	}

public:

	void CheckMaps() {
		vec_button.clear();
		vec_map_list.clear();
		const string path = "maps\\";
		const string extension = ".wemap";
		for (auto& p : fs::directory_iterator(path)) {
			if (p.path().extension().string() == extension) {
				string fNime = p.path().filename().string();
				fNime.erase(fNime.length() - 6);
				vec_map_list.push_back(fNime);
			}
		}

		sort(vec_map_list.begin(), vec_map_list.end(), SortABC);

		for (auto& map_name : vec_map_list) {
			vec_button.push_back(make_unique<ButtonClickActiveWithText>(CreateShape(v2f(scr_W / 2, scr_H / 2 + vec_button.size() * 25), v2f(120, 24), Color(100, 100, 100)), map_name));
		}
	}

	MenuMapSelect() {
	}

	void Update() {
		for (auto& button : vec_button) {
			button->Update();
		}
	}

	void Action() {
		for (auto& button : vec_button) {
			if (button->Action()) {
				cout << button->GetActionId() << endl;
			}
		}
	}

	void Draw() {
		for (auto& button : vec_button) {
			button->Draw();
		}
	}

	~MenuMapSelect() {

	}
};